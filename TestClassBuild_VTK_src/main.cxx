#include <iostream>
#include "ReadWriteImg.h"
#include "VisualizeData.h"
#include "ApplyRegistration.h"
#include "PatchData.h"
#include "vtkFloatArray.h"

using namespace std;

int main( int argc, char* argv[] ){

	if (argc < 5){

		std::cerr << "Nope! Usage: " ;
		std::cerr << "<filename_Static> <filename_Dynamic> <filename_centerline> <outputfilename>" << endl;
	return EXIT_FAILURE;
	}

	cout << "number of arguments is : " << argc << endl;

//	ApplyRegistration outputReg(argv[1],argv[2],argv[4]);
//
//	outputReg.writeSTL();

	int nPlanes = 12;

	//visualize the results
	//input : filename_StaticMesh, filenames_outputfile, filename_centerline
//	visualizeData visualizer(argv[1],argv[4],argv[3],nPlanes);
//
//	visualizer.renderActors();
	ReadWriteImg year1mesh(argv[1]);
	ReadWriteImg year4mesh(argv[4]);
	ReadWriteImg centerlineMesh(argv[3]);

	int min = 6;
	int max = 7;

	PatchData buildPatch(year1mesh.getPdata(),centerlineMesh.getPdata(),min,max,nPlanes);
//	testPoly = buildPatch.clipSection();
	VisualizeData showData;

	vtkSmartPointer<vtkPolyData> patch = vtkSmartPointer<vtkPolyData>::New();
	vtkSmartPointer<vtkPolyData> filledPatch = vtkSmartPointer<vtkPolyData>::New();

	patch->DeepCopy(buildPatch.clipSection(year1mesh.getPdata()));

	buildPatch.getCellNormals(patch);

	vtkSmartPointer<vtkFloatArray> fArray = vtkSmartPointer<vtkFloatArray>::New();



	//	filledPatch = buildPatch.closePatch(patch);
//
//	//Show patch
//	showData.simpleShowPolyData(filledPatch,
//								buildPatch.clipSection(year4mesh.getPdata()));

	//Show full aorta
//	showData.simpleShowPolyData(year1mesh.getPdata(),
//								year4mesh.getPdata());

	return 0;
}
