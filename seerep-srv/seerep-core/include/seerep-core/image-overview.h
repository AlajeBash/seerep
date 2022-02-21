#ifndef SEEREP_CORE_IMAGE_OVERVIEW_H_
#define SEEREP_CORE_IMAGE_OVERVIEW_H_

#include <functional>
#include <optional>

// seerep-msgs
#include <seerep-msgs/boundingbox.pb.h>
#include <seerep-msgs/image.pb.h>
#include <seerep-msgs/query.pb.h>
// seerep-hdf5
#include <seerep-hdf5/image-io.h>
// seerep-conversion
#include <seerep_ros_conversions/conversions.h>

// seerep-core
#include "image.h"
#include "aabb-hierarchy.h"
#include "tf-overview.h"

// uuid
#include <boost/uuid/uuid.hpp>             // uuid class
#include <boost/uuid/uuid_generators.hpp>  // generators
#include <boost/uuid/uuid_io.hpp>          // streaming operators etc.
#include <boost/lexical_cast.hpp>
#include <boost/functional/hash.hpp>

namespace seerep_core
{
class ImageOverview
{
public:
  ImageOverview(std::shared_ptr<seerep_hdf5::ImageIO> hdf5_io, std::shared_ptr<seerep_core::TFOverview> tfOverview,
                std::string frameId);
  ~ImageOverview();
  std::vector<std::optional<seerep::Image>> getData(const seerep::Query& bb);

  boost::uuids::uuid addDataset(const seerep::Image& image);

private:
  void recreateDatasets();
  void addImageToIndices(std::shared_ptr<seerep_core::Image> img);

  void tryAddingDataWithMissingTF();
  std::vector<AabbHierarchy::AabbIdPair> querySpatial(const seerep::Query& query);
  std::vector<AabbHierarchy::AabbTimeIdPair> queryTemporal(const seerep::Query& query);
  std::set<uint64_t> querySemantic(const seerep::Query& query);

  std::vector<uint64_t> intersectQueryResults(std::vector<AabbHierarchy::AabbIdPair> rt_result,
                                              std::vector<AabbHierarchy::AabbTimeIdPair> timetree_result,
                                              std::set<uint64_t> semanticResult);

  uint64_t m_data_count;

  std::string m_frameId;
  std::shared_ptr<seerep_core::TFOverview> m_tfOverview;
  std::shared_ptr<seerep_hdf5::ImageIO> m_hdf5_io;

  std::unordered_map<uint64_t, std::shared_ptr<seerep_core::Image>> m_datasets;

  std::vector<std::shared_ptr<seerep_core::Image>> m_dataWithMissingTF;
  AabbHierarchy::rtree m_rt;
  AabbHierarchy::timetree m_timetree;
  std::unordered_map<std::string, std::vector<uint64_t>> m_label;
};

} /* namespace seerep_core */

#endif  // SEEREP_CORE_IMAGE_OVERVIEW_H_
