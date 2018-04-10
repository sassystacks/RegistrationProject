
cmake_minimum_required(VERSION 2.8)

PROJECT(FinalProject)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

if (ITKVtkGlue_LOADED)
  find_package(VTK REQUIRED)
  include(${VTK_USE_FILE})
else()
  find_package(ItkVtkGlue REQUIRED)
  include(${ItkVtkGlue_USE_FILE})
  set(Glue ItkVtkGlue)
endif()

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

#set( HEADER_DIR /home/richard/eclipse-workspace/TestClassBuild_VTK_build )

#set(SOURCES
#	fProjectMain.cxx
#	Circle.cpp /home/richard/eclipse-workspace/TestClassBuild_VTK_src/Circle.h
#	Rectangle.cpp /home/richard/eclipse-workspace/TestClassBuild_VTK_src/Rectangle.h
#	Square.cpp /home/richard/eclipse-workspace/TestClassBuild_VTK_src/Square.h
#	Shape.h)

file(GLOB SOURCES "*.cpp")

include_directories(include)

add_executable(FinalProjectMain ${SOURCES})

target_link_libraries(FinalProjectMain ${VTK_LIBRARIES} ${ITK_LIBRARIES})
