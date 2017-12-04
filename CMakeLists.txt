cmake_minimum_required(VERSION 2.6)
project(grid_map_cereal)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(Eigen3 QUIET)
if(NOT EIGEN3_FOUND)
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(EIGEN3 REQUIRED eigen3)
  set(EIGEN3_INCLUDE_DIR ${EIGEN3_INCLUDE_DIRS})
endif()

find_package(grid_map_core REQUIRED)

include_directories(
  src
  ${EIGEN3_INCLUDE_DIR}
  ${grid_map_core_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}
  src/GridMapCereal.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${grid_map_core_LIBRARIES}
)

