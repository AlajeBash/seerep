#include "seerep-hdf5-core/hdf5-core-image.h"

#include <highfive/H5DataSet.hpp>

namespace seerep_hdf5_core
{
Hdf5CoreImage::Hdf5CoreImage(std::shared_ptr<HighFive::File>& file, std::shared_ptr<std::mutex>& write_mtx)
  : Hdf5CoreGeneral(file, write_mtx)
{
}

std::optional<seerep_core_msgs::DatasetIndexable> Hdf5CoreImage::readImage(const boost::uuids::uuid& uuid)
{
  return readImage(boost::lexical_cast<std::string>(uuid));
}

std::optional<seerep_core_msgs::DatasetIndexable> Hdf5CoreImage::readImage(const std::string& uuid)
{
  std::string hdf5DatasetPath = HDF5_GROUP_IMAGE + "/" + uuid;
  std::string hdf5DatasetRawDataPath = hdf5DatasetPath + "/" + seerep_hdf5_core::Hdf5CoreImage::RAWDATA;

  if (!m_file->exist(hdf5DatasetPath) || !m_file->exist(hdf5DatasetRawDataPath))
    return std::nullopt;

  std::shared_ptr<HighFive::DataSet> data_set_ptr =
      std::make_shared<HighFive::DataSet>(m_file->getDataSet(hdf5DatasetRawDataPath));

  seerep_core_msgs::DatasetIndexable data;

  data.header.frameId =
      getAttribute<std::string>(hdf5DatasetRawDataPath, data_set_ptr, seerep_hdf5_core::Hdf5CoreImage::HEADER_FRAME_ID);
  data.header.timestamp.seconds = getAttribute<int64_t>(hdf5DatasetRawDataPath, data_set_ptr,
                                                        seerep_hdf5_core::Hdf5CoreImage::HEADER_STAMP_SECONDS);
  data.header.timestamp.nanos =
      getAttribute<int64_t>(hdf5DatasetRawDataPath, data_set_ptr, seerep_hdf5_core::Hdf5CoreImage::HEADER_STAMP_NANOS);

  // set bounding box for images to 0. assume no spatial extent
  data.boundingbox.min_corner().set<0>(0);
  data.boundingbox.min_corner().set<1>(0);
  data.boundingbox.min_corner().set<2>(0);
  data.boundingbox.max_corner().set<0>(0);
  data.boundingbox.max_corner().set<1>(0);
  data.boundingbox.max_corner().set<2>(0);

  std::vector<std::string> labelsGeneral = readLabelsGeneral(hdf5DatasetPath);
  std::vector<std::string> labelsBB = readBoundingBox2DLabels(hdf5DatasetPath);

  data.labels.insert(std::end(data.labels), std::begin(labelsGeneral), std::end(labelsGeneral));
  data.labels.insert(std::end(data.labels), std::begin(labelsBB), std::end(labelsBB));

  return data;
}

std::vector<std::string> Hdf5CoreImage::readLabelsGeneral(const std::string& dataGroup)
{
  if (!m_file->exist(dataGroup + "/" + seerep_hdf5_core::Hdf5CoreGeneral::LABELGENERAL))
  {
    std::cout << "id " << dataGroup + "/" + seerep_hdf5_core::Hdf5CoreGeneral::LABELGENERAL
              << " does not exist in file " << m_file->getName() << std::endl;
    return std::vector<std::string>();
  }

  std::vector<std::string> labels;
  HighFive::DataSet datasetLabels =
      m_file->getDataSet(dataGroup + "/" + seerep_hdf5_core::Hdf5CoreGeneral::LABELGENERAL);
  datasetLabels.read(labels);

  return labels;
}

std::vector<std::string> Hdf5CoreImage::readBoundingBox2DLabels(const std::string& dataGroup)
{
  if (!m_file->exist(dataGroup + "/" + seerep_hdf5_core::Hdf5CoreGeneral::LABELBB))
  {
    std::cout << "id " << dataGroup + "/" + seerep_hdf5_core::Hdf5CoreGeneral::LABELBB << " does not exist in file "
              << m_file->getName() << std::endl;
    return std::vector<std::string>();
  }

  std::vector<std::string> labels;

  HighFive::DataSet datasetLabels = m_file->getDataSet(dataGroup + "/" + seerep_hdf5_core::Hdf5CoreGeneral::LABELBB);
  datasetLabels.read(labels);

  return labels;
}

}  // namespace seerep_hdf5_core