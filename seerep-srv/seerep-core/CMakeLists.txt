cmake_minimum_required(VERSION 3.0.2)
project(seerep-core VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC -DBOOST_LOG_DYN_LINK")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SeerepHdf5Core REQUIRED)
find_package(Protobuf REQUIRED)
find_package(SeerepMsgs REQUIRED)
find_package(HighFive REQUIRED)
find_package(
  Eigen3
  3.3
  REQUIRED
  NO_MODULE
)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(
  Boost
  COMPONENTS log log_setup
  REQUIRED
)

find_package(catkin REQUIRED COMPONENTS tf2)

configure_file(include/SeerepCoreConfig.h.in SeerepCoreConfig.h)

include_directories(
  include
  ${SeerepMsgs_INCLUDE_DIRS}
  ${SeerepHdf5Core_INCLUDE_DIRS}
  ${seerep_ros_conversions_INCLUDE_DIRS}
  ${PROTOBUF_INCLUDE_DIR}
  ${HighFive_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_library(
  seerepcore
  src/core-dataset.cpp
  src/core-instance.cpp
  src/core-instances.cpp
  src/core-project.cpp
  src/core-tf.cpp
  src/core.cpp
)

target_link_libraries(
  seerepcore
  ${SeerepMsgs_LIBRARIES}
  ${SeerepHdf5Core_LIBRARIES}
  ${seerep_ros_conversions_LIBRARIES}
  ${PROTOBUF_LIBRARIES}
  ${HighFive_LIBRARIES}
  ${Boost_LIBRARIES}
  ${Boost_LOG_LIBRARY}
  ${Boost_LOG_SETUP_LIBRARY}
  ${catkin_LIBRARIES}
  Eigen3::Eigen
)

set(INSTALL_HEADERS
    include/seerep-core/core-dataset.h
    include/seerep-core/core-instance.h
    include/seerep-core/core-instances.h
    include/seerep-core/core-project.h
    include/seerep-core/core-tf.h
    include/seerep-core/core.h
)

set_target_properties(seerepcore PROPERTIES PUBLIC_HEADER "${INSTALL_HEADERS}")

set(CMAKE_INSTALL_INCLUDEDIR include)
set(CMAKE_INSTALL_LIBDIR lib)
set(CMAKE_INSTALL_BINDIR bin)

install(
  TARGETS seerepcore
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)
include(CMakePackageConfigHelpers)

configure_package_config_file(
  cmake/SeerepCoreConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/SeerepCoreConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR
)

# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/SeerepCoreConfigVersion.cmake"
  VERSION "${seerep_core_VERSION_MAJOR}.${seerep_core_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

# install the configuration file
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/SeerepCoreConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/SeerepCoreConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SeerepCore
)

install(FILES "${PROJECT_BINARY_DIR}/SeerepCoreConfig.h"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)
