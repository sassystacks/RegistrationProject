
cmake_minimum_required(VERSION 2.8)
 
PROJECT(DeleteCells)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(DeleteCells MACOSX_BUNDLE DeleteCells.cxx )
 
target_link_libraries(DeleteCells ${VTK_LIBRARIES})
