#!/usr/bin/env python3

import os
import sys
import time

import boundingbox2d_labeled_pb2 as bb
import grpc
import image_pb2 as image
import image_service_pb2_grpc as imageService
import label_with_instance_pb2 as labelWithInstance
import meta_operations_pb2_grpc as metaOperations
import numpy as np
import projectCreation_pb2 as projectCreation
import tf_service_pb2_grpc as tfService
import transform_stamped_pb2 as tf
from google.protobuf import empty_pb2

# # server with certs
# __location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
# with open(os.path.join(__location__, '../tls.pem'), 'rb') as f:
#     root_cert = f.read()
# server = "seerep.robot.10.249.3.13.nip.io:32141"
# creds = grpc.ssl_channel_credentials(root_cert)
# channel = grpc.secure_channel(server, creds)

# server without certs
server = "localhost:9090"
channel = grpc.insecure_channel(server)

stub = imageService.ImageServiceStub(channel)
stubTf = tfService.TfServiceStub(channel)
stubMeta = metaOperations.MetaOperationsStub(channel)

response = stubMeta.GetProjects(empty_pb2.Empty())

found = False
for project in response.projects:
    print(project.name + " " + project.uuid)
    if project.name == "testproject":
        projectuuid = project.uuid
        found = True

if not found:
    creation = projectCreation.ProjectCreation(name="testproject", mapFrameId="map")
    projectCreated = stubMeta.CreateProject(creation)
    projectuuid = projectCreated.uuid


theTime = int(time.time())

for n in range(10):
    theImage = image.Image()

    rgb = []
    lim = 256
    for i in range(lim):
        for j in range(lim):
            x = float(i) / lim
            y = float(j) / lim
            z = float(j) / lim
            r = np.ubyte((x * 255.0 + n) % 255)
            g = np.ubyte((y * 255.0 + n) % 255)
            b = np.ubyte((z * 255.0 + n) % 255)
            # print(r, g, b)
            rgb.append(r)
            rgb.append(g)
            rgb.append(b)

    theImage.header.frame_id = "camera"
    theImage.header.stamp.seconds = theTime + n
    theImage.header.stamp.nanos = 0
    theImage.header.uuid_project = projectuuid
    theImage.height = lim
    theImage.width = lim
    theImage.encoding = "rgb8"
    theImage.step = 3 * lim
    theImage.data = bytes(rgb)

    bb1 = bb.BoundingBox2DLabeled()
    for i in range(0, 10):
        bb1.labelWithInstance.label = "testlabel" + str(i)
        bb1.boundingBox.point_min.x = 0.01 + i / 10
        bb1.boundingBox.point_min.y = 0.02 + i / 10
        bb1.boundingBox.point_max.x = 0.03 + i / 10
        bb1.boundingBox.point_max.y = 0.04 + i / 10
        theImage.labels_bb.append(bb1)

    for i in range(0, 10):
        label = labelWithInstance.LabelWithInstance()
        label.label = "testlabelgeneral" + str(i)
        theImage.labels_general.append(label)

    uuidImg = stub.TransferImage(theImage)

    print("uuid of transfered img: " + uuidImg.message)

theTf = tf.TransformStamped()
theTf.header.frame_id = "map"
theTf.header.stamp.seconds = theTime
theTf.header.uuid_project = projectuuid
theTf.child_frame_id = "camera"
theTf.transform.translation.x = 1
theTf.transform.translation.y = 2
theTf.transform.translation.z = 3
theTf.transform.rotation.x = 0
theTf.transform.rotation.y = 0
theTf.transform.rotation.z = 0
theTf.transform.rotation.w = 1
stubTf.TransferTransformStamped(theTf)

theTf.header.stamp.seconds = theTime + 10
theTf.transform.translation.x = 100
theTf.transform.translation.y = 200
theTf.transform.translation.z = 300
stubTf.TransferTransformStamped(theTf)