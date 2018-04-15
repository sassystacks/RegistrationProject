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

	ReadWriteImg year1mesh(argv[1]);
	ReadWriteImg year4mesh(argv[4]);
	ReadWriteImg centerlineMesh(argv[3]);

	int min = 6;
	int max = 7;

	PatchData buildPatch(year1mesh.getPdata(),centerlineMesh.getPdata(),min,max,nPlanes);

	VisualizeData showData;


//	//Make Patch
//	vtkSmartPointer<vtkPolyData> patch = vtkSmartPointer<vtkPolyData>::New();
//	vtkSmartPointer<vtkPolyData> filledPatch = vtkSmartPointer<vtkPolyData>::New();
//
//	//Make a copy of the clipped section as patch
//	patch->DeepCopy(buildPatch.clipSection(year1mesh.getPdata()));
//
//	//Output the details of the normals of the patch to terminal
//	buildPatch.CellNormals(patch);
//
//	//get the Normals of the patch
//	vtkSmartPointer<vtkPolyDataNormals> norms= vtkSmartPointer<vtkPolyDataNormals>::New();
//	norms = buildPatch.getCellNormals();

	//show the normals
//	showData.visualizeNormals(patch,norms);
//	showData.simpleShowPolyData(patch);
//	// Double normals in an array
//	vtkFloatArray* normalDataFloat =
//			vtkFloatArray::SafeDownCast(patch->GetCellData()->GetArray("Normals"));
//
//
//	showData.visualizeNormals(patch,buildPatch.getCellNormals());
//		filledPatch = buildPatch.closePatch(patch);

	//Show patch

	//show normal from reference configuration to current configuration
	buildPatch.setCellntersectData(year1mesh.getPdata(),year4mesh.getPdata());

	//show 2 meshes input
//	showData.simpleShowPolyData(year4mesh.getPdata(),year1mesh.getPdata());

	//Show full aorta
//	showData.renderActors();

	return 0;
}
