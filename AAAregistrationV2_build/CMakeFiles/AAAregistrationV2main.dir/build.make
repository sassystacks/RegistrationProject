# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_build

# Include any dependencies generated for this target.
include CMakeFiles/AAAregistrationV2main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AAAregistrationV2main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AAAregistrationV2main.dir/flags.make

CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o: CMakeFiles/AAAregistrationV2main.dir/flags.make
CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o: /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_src/AAAregister2.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o -c /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_src/AAAregister2.cxx

CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_src/AAAregister2.cxx > CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.i

CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_src/AAAregister2.cxx -o CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.s

CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o.requires:

.PHONY : CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o.requires

CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o.provides: CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o.requires
	$(MAKE) -f CMakeFiles/AAAregistrationV2main.dir/build.make CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o.provides.build
.PHONY : CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o.provides

CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o.provides.build: CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o


# Object files for target AAAregistrationV2main
AAAregistrationV2main_OBJECTS = \
"CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o"

# External object files for target AAAregistrationV2main
AAAregistrationV2main_EXTERNAL_OBJECTS =

AAAregistrationV2main: CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o
AAAregistrationV2main: CMakeFiles/AAAregistrationV2main.dir/build.make
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOInfovis-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingContextOpenGL2-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkTestingRendering-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkViewsContext2D-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersProgrammable-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersVerdict-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersGeneric-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkTestingGenericBridge-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkDomainsChemistryOpenGL2-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOAMR-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOExodus-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingVolumeOpenGL2-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersFlowPaths-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersHyperTree-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingStencil-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersParallelImaging-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersPoints-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersSMP-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersSelection-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOParallel-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersTexture-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersTopology-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkGeovisCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOEnSight-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOExportOpenGL2-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkInteractionImage-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOImport-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOLSDyna-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOMINC-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOMovie-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOPLY-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOParallelXML-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOSQL-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkTestingIOSQL-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOTecplotTable-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOVideo-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingStatistics-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingImage-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingMorphological-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingLOD-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkViewsInfovis-9.0.so.1
AAAregistrationV2main: /usr/local/lib/libitkdouble-conversion-5.0.a
AAAregistrationV2main: /usr/local/lib/libitksys-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkvnl_algo-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkvnl-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkv3p_netlib-5.0.a
AAAregistrationV2main: /usr/local/lib/libitknetlib-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkvcl-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKCommon-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKEXPAT-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkzlib-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKznz-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKniftiio-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKgiftiio-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOImageBase-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkNetlibSlatec-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKStatistics-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKTransform-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKMesh-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOMesh-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkIOSTL-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKQuadEdgeMesh-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOBMP-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmDICT-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmMSFF-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOGDCM-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOGIPL-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkjpeg-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOJPEG-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKMetaIO-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOMeta-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIONIFTI-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKNrrdIO-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIONRRD-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkpng-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOPNG-5.0.a
AAAregistrationV2main: /usr/local/lib/libitktiff-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOTIFF-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOVTK-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKLabelMap-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKSpatialObjects-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKPath-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKOptimizers-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKPolynomials-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKBiasCorrection-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKDICOMParser-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkhdf5_cpp.a
AAAregistrationV2main: /usr/local/lib/libitkhdf5.a
AAAregistrationV2main: /usr/local/lib/libITKIOBioRad-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOBruker-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOCSV-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOIPL-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOGE-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOSiemens-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOHDF5-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOLSM-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkminc2-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOMINC-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOMRC-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOXML-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOSpatialObjects-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOStimulate-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKTransformFactory-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOTransformBase-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOTransformHDF5-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOTransformInsightLegacy-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOTransformMatlab-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKKLMRegionGrowing-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKVTK-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKWatersheds-5.0.a
AAAregistrationV2main: /usr/local/lib/libitklbfgs-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKOptimizersv4-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKVideoCore-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKVideoIO-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKVtkGlue-5.0.a
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtklibxml2-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkverdict-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkDomainsChemistry-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersAMR-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingMath-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOGeometry-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkexodusII-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersParallel-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIONetCDF-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtknetcdfcpp-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkjsoncpp-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkproj4-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOExport-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingGL2PSOpenGL2-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkgl2ps-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtklibharu-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkNetCDF-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkhdf5-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkhdf5_hl-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtktheora-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkogg-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkParallelCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOLegacy-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtksqlite-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkChartsCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingContext2D-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkViewsCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkInteractionWidgets-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersHybrid-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingAnnotation-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingColor-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingVolume-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOXML-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOXMLParser-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtklz4-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtklzma-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkexpat-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersImaging-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingGeneral-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingLabel-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkInfovisLayout-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkInfovisCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersModeling-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingHybrid-9.0.so.1
AAAregistrationV2main: /usr/local/lib/libITKIOMesh-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKgiftiio-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmMSFF-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmDICT-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmIOD-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmDSED-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmCommon-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmjpeg8-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmjpeg12-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmjpeg16-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmopenjp2-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmcharls-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkgdcmuuid-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKMetaIO-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKniftiio-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKznz-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKNrrdIO-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkpng-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOIPL-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOTIFF-5.0.a
AAAregistrationV2main: /usr/local/lib/libitktiff-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkjpeg-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkminc2-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOXML-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKEXPAT-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkhdf5_cpp.a
AAAregistrationV2main: /usr/local/lib/libitkhdf5.a
AAAregistrationV2main: /usr/local/lib/libitkzlib-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOTransformBase-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKTransformFactory-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKSpatialObjects-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKMesh-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKTransform-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKPath-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKOptimizers-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKStatistics-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkNetlibSlatec-5.0.a
AAAregistrationV2main: /usr/local/lib/libitklbfgs-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKIOImageBase-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKVideoCore-5.0.a
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingFreeType-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkfreetype-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingOpenGL2-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkglew-9.0.so.1
AAAregistrationV2main: /usr/lib/libSM.so
AAAregistrationV2main: /usr/lib/libICE.so
AAAregistrationV2main: /usr/lib/libX11.so
AAAregistrationV2main: /usr/lib/libXext.so
AAAregistrationV2main: /usr/lib/libXt.so
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkIOImage-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkDICOMParser-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkmetaio-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkzlib-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkjpeg-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkpng-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtktiff-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingSources-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkInteractionStyle-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersExtraction-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersStatistics-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingFourier-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkImagingCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkRenderingCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonColor-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersGeometry-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersSources-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersGeneral-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonComputationalGeometry-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkFiltersCore-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonExecutionModel-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonDataModel-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonMisc-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonSystem-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtksys-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonTransforms-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonMath-9.0.so.1
AAAregistrationV2main: /home/richard/gitSource/VTK_Release_Build/lib/libvtkCommonCore-9.0.so.1
AAAregistrationV2main: /usr/local/lib/libITKVTK-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKCommon-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkdouble-conversion-5.0.a
AAAregistrationV2main: /usr/local/lib/libitksys-5.0.a
AAAregistrationV2main: /usr/local/lib/libITKVNLInstantiation-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkvnl_algo-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkvnl-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkv3p_netlib-5.0.a
AAAregistrationV2main: /usr/local/lib/libitknetlib-5.0.a
AAAregistrationV2main: /usr/local/lib/libitkvcl-5.0.a
AAAregistrationV2main: CMakeFiles/AAAregistrationV2main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AAAregistrationV2main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AAAregistrationV2main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AAAregistrationV2main.dir/build: AAAregistrationV2main

.PHONY : CMakeFiles/AAAregistrationV2main.dir/build

CMakeFiles/AAAregistrationV2main.dir/requires: CMakeFiles/AAAregistrationV2main.dir/AAAregister2.cxx.o.requires

.PHONY : CMakeFiles/AAAregistrationV2main.dir/requires

CMakeFiles/AAAregistrationV2main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AAAregistrationV2main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AAAregistrationV2main.dir/clean

CMakeFiles/AAAregistrationV2main.dir/depend:
	cd /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_src /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_src /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_build /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_build /home/richard/MyProjects/Tutorials/ITK/AAAregistrationV2_build/CMakeFiles/AAAregistrationV2main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AAAregistrationV2main.dir/depend
