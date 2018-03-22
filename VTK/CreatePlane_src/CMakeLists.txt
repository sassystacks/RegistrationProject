
cmake_minimum_required(VERSION 2.8)
 
PROJECT(PlaneCreator)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(PointCreatormain MACOSX_BUNDLE main.cxx )
 
target_link_libraries(PointCreatormain ${VTK_LIBRARIES})
