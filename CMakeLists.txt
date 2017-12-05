cmake_minimum_required(VERSION 2.6)
project(grid_map_cereal)

###############
### General ###
###############
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/)
set(CMAKE_INCLUDE_DIR ${CMAKE_SOURCE_DIR})

include(ExternalProject)
find_package(Eigen3 REQUIRED)
find_package(grid_map_core REQUIRED)

##############
### Cereal ###
##############
set(CEREAL_PROJECT_NAME cereal)

ExternalProject_Add(${CEREAL_PROJECT_NAME}
  PREFIX ${CMAKE_BINARY_DIR}/${CEREAL_PROJECT_NAME}
  GIT_REPOSITORY https://github.com/USCiLab/cereal
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(${CEREAL_PROJECT_NAME} source_dir)
set(CEREAL_INCLUDE_DIR ${source_dir}/include/)

#############
### Build ###
#############
include_directories(
  ${EIGEN3_INCLUDE_DIR}
  ${grid_map_core_INCLUDE_DIRS}
  ${CEREAL_INCLUDE_DIR}
)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_SOURCE_DIR}/GridMapCereal.cpp
)

# Make the build wait for this dependency
add_dependencies(${PROJECT_NAME}
  ${CEREAL_PROJECT_NAME}
)

target_link_libraries(${PROJECT_NAME}
  ${grid_map_core_LIBRARIES}
)

##################
### Pkg Config ###
##################
configure_file(
  ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc @ONLY
)

###############
### Install ###
###############
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc
  DESTINATION lib/pkgconfig
)

install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
)

install(
  DIRECTORY ${CMAKE_INCLUDE_DIR}
  DESTINATION include/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.hpp"
)

install(
  DIRECTORY ${CEREAL_INCLUDE_DIR}/cereal/
  DESTINATION include/${CEREAL_PROJECT_NAME}
)

