cmake_minimum_required(VERSION 2.6)
project(grid_map_cereal)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(Eigen3 REQUIRED)
find_package(grid_map_core REQUIRED)

include_directories(
  ${EIGEN3_INCLUDE_DIRS}
  ${grid_map_core_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} SHARED
  src/GridMapCereal.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${grid_map_core_LIBRARIES}
)

install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
)

install(
  DIRECTORY src/
  DESTINATION include/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.hpp"
)

