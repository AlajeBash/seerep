#include "seerep_ros_communication/querier.h"
#include "seerep_ros_communication/types.h"
#include <grpc/status.h>

namespace seerep_grpc_ros
{
QueryData::QueryData(std::shared_ptr<grpc::Channel> channel_ptr)
  : stub_(seerep::TransferSensorMsgs::NewStub(channel_ptr))
{
}

void seerep_grpc_ros::QueryData::queryPointcloud(const seerep::Boundingbox& bb, sensor_msgs::PointCloud2& pc2) const
{
  grpc::ClientContext context;
  seerep::PointCloud2 response;
  grpc::Status status = stub_->GetPointCloud2(&context, bb, &response);
  if (!status.ok())
  {
    ROS_ERROR_STREAM("gRPC status error code: " << status.error_code() << " " << status.error_message());
  }
  else
  {
    pc2 = seerep_ros_conversions::toROS(response);
  }
}

} /* namespace seerep_grpc_ros */

int main(int argc, char** argv)
{
  ros::init(argc, argv, "seerep_ros_communication_client");
  ros::NodeHandle nh;
  ros::NodeHandle private_nh("~");
  ros::Publisher pc2_pub = nh.advertise<sensor_msgs::PointCloud2>("queried_pc", 1000);

  std::string server_address;
  private_nh.param<std::string>("server_address", server_address, "localhost:9090");

  seerep_grpc_ros::QueryData query_data(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));

  seerep::Boundingbox bb;
  bb.mutable_point_min()->set_x(0);
  bb.mutable_point_min()->set_y(0);
  bb.mutable_point_min()->set_z(0);
  bb.mutable_point_max()->set_x(1);
  bb.mutable_point_max()->set_y(1);
  bb.mutable_point_max()->set_z(1);
  sensor_msgs::PointCloud2 queriedPc;
  query_data.queryPointcloud(bb, queriedPc);
  queriedPc.header.frame_id = "map";
  // ROS_INFO_STREAM("publish pointcloud" << queriedPc);
  pc2_pub.publish(queriedPc);

  ros::spinOnce();

  return EXIT_SUCCESS;
}