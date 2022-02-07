#include "seerep-core/tf-overview.h"

namespace seerep_core
{
// construct tfbuffer with INT_MAX so that it holds ALL tfs added
TFOverview::TFOverview(std::shared_ptr<seerep_hdf5::SeerepHDF5IO> hdf5_io)
  : m_hdf5_io(hdf5_io), m_tfbuffer(ros::DURATION_MAX)
{
  recreateDatasets();
}
TFOverview::~TFOverview()
{
}

void TFOverview::recreateDatasets()
{
  std::vector<std::string> tfs = m_hdf5_io->getGroupDatasets("tf");
  for (auto const& name : tfs)
  {
    std::cout << "found " << name << " in HDF5 file." << std::endl;

    try
    {
      auto tf = std::make_shared<TF>(m_hdf5_io, name);

      addToIndices(tf);

      std::optional<std::vector<seerep::TransformStamped>> transforms = tf->getData();
      if (transforms)
      {
        for (auto& transform : transforms.value())

          addToTfBuffer(transform);
      }
    }
    catch (const std::runtime_error& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
}

std::optional<seerep::TransformStamped> TFOverview::getData(const int64_t& timesecs, const int64_t& timenanos,
                                                            const std::string& targetFrame,
                                                            const std::string& sourceFrame)
{
  // if (!ros::Time::isValid())
  // {
  //   ros::Time::init();
  // }

  try
  {
    return seerep_ros_conversions::toProto(
        m_tfbuffer.lookupTransform(targetFrame, sourceFrame, ros::Time(timesecs, timenanos)));
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << std::endl;
    return std::nullopt;
  }
}

void TFOverview::addDataset(const seerep::TransformStamped& transform)
{
  addToTfBuffer(transform);

  auto tfInMap = m_datasets.find(TF::idFromFrameNames(transform.header().frame_id(), transform.child_frame_id()));
  if (tfInMap == m_datasets.end())
  {
    // create new tf object and add to map if not existing yet
    auto tf = std::make_shared<seerep_core::TF>(m_hdf5_io, transform);
    addToIndices(tf);
  }
  else
  {
    // add transform to tf object
    tfInMap->second->addData(transform);
  }
}

// TODO optimise!
AabbHierarchy::AABB TFOverview::transformAABB(AabbHierarchy::AABB aabb, const std::string& sourceFrame,
                                              const std::string& targetFrame, const int64_t& timeSecs,
                                              const int64_t& timeNanos)
{
  if (targetFrame != sourceFrame)
  {
    auto tf = m_tfbuffer.lookupTransform(targetFrame, sourceFrame, ros::Time(timeSecs, timeNanos));
    tf2::Transform transform;
    transform.setOrigin(
        tf2::Vector3(tf.transform.translation.x, tf.transform.translation.y, tf.transform.translation.z));
    transform.setRotation(tf2::Quaternion(tf.transform.rotation.x, tf.transform.rotation.y, tf.transform.rotation.z,
                                          tf.transform.rotation.w));

    tf2::Vector3 vmin(bg::get<bg::min_corner, 0>(aabb), bg::get<bg::min_corner, 1>(aabb),
                      bg::get<bg::min_corner, 2>(aabb));
    tf2::Vector3 vmintransformed = transform * vmin;
    bg::set<bg::min_corner, 0>(aabb, vmintransformed.getX());
    bg::set<bg::min_corner, 1>(aabb, vmintransformed.getY());
    bg::set<bg::min_corner, 2>(aabb, vmintransformed.getZ());

    tf2::Vector3 vmax(bg::get<bg::max_corner, 0>(aabb), bg::get<bg::max_corner, 1>(aabb),
                      bg::get<bg::max_corner, 2>(aabb));
    tf2::Vector3 vmaxtransformed = transform * vmax;
    bg::set<bg::max_corner, 0>(aabb, vmaxtransformed.getX());
    bg::set<bg::max_corner, 1>(aabb, vmaxtransformed.getY());
    bg::set<bg::max_corner, 2>(aabb, vmaxtransformed.getZ());
  }
  return aabb;
}

bool TFOverview::canTransform(const std::string& sourceFrame, const std::string& targetFrame, const int64_t& timeSecs,
                              const int64_t& timeNanos)
{
  return m_tfbuffer.canTransform(targetFrame, sourceFrame, ros::Time(timeSecs, timeNanos));
}

seerep::Query TFOverview::transformQuery(const seerep::Query& query, std::string targetFrame)
{
  if (targetFrame != query.boundingbox().header().frame_id())
  {
    seerep::Query queryTransformed(query);

    auto tf = m_tfbuffer.lookupTransform(targetFrame, query.boundingbox().header().frame_id(),
                                         ros::Time(query.boundingbox().header().stamp().seconds(),
                                                   query.boundingbox().header().stamp().nanos()));
    tf2::Transform transform;
    transform.setOrigin(
        tf2::Vector3(tf.transform.translation.x, tf.transform.translation.y, tf.transform.translation.z));
    transform.setRotation(tf2::Quaternion(tf.transform.rotation.x, tf.transform.rotation.y, tf.transform.rotation.z,
                                          tf.transform.rotation.w));

    tf2::Vector3 vmin(query.boundingbox().point_min().x(), query.boundingbox().point_min().y(),
                      query.boundingbox().point_min().z());
    tf2::Vector3 vmintransformed = transform * vmin;
    queryTransformed.mutable_boundingbox()->mutable_point_min()->set_x(vmintransformed.getX());
    queryTransformed.mutable_boundingbox()->mutable_point_min()->set_y(vmintransformed.getY());
    queryTransformed.mutable_boundingbox()->mutable_point_min()->set_z(vmintransformed.getZ());

    tf2::Vector3 vmax(query.boundingbox().point_max().x(), query.boundingbox().point_max().y(),
                      query.boundingbox().point_max().z());
    tf2::Vector3 vmaxtransformed = transform * vmax;
    queryTransformed.mutable_boundingbox()->mutable_point_max()->set_x(vmaxtransformed.getX());
    queryTransformed.mutable_boundingbox()->mutable_point_max()->set_y(vmaxtransformed.getY());
    queryTransformed.mutable_boundingbox()->mutable_point_max()->set_z(vmaxtransformed.getZ());

    return queryTransformed;
  }
  else
  {
    return query;
  }
}

void TFOverview::addToIndices(std::shared_ptr<seerep_core::TF> tf)
{
  m_datasets.insert(std::make_pair(tf->getID(), tf));
}

void TFOverview::addToTfBuffer(seerep::TransformStamped transform)
{
  m_tfbuffer.setTransform(seerep_ros_conversions::toROS(transform), "fromHDF5");
}

// for (auto tf : m_datasets)
// {
//   std::optional<std::vector<seerep::TransformStamped>> transforms = tf.second->getData();

//   for (auto transform : transforms.value())
//   {
//     tfbuffer.setTransform(seerep_ros_conversions::toROS(transform), "fromHDF5");
//   }

//   std::cout << "loaded from hdf5: " << std::endl tfbuffer.allFramesAsString() << std::endl;
// }

} /* namespace seerep_core */