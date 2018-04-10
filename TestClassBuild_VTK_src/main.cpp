#include <iostream>
#include "ReadWriteImg.h"
#include "visualizeData.h"
#include "ApplyRegistration.h"
#include "vtkvmtkCenterlineAttributesFilter.h"

using namespace std;

int main( int argc, char* argv[] ){

	if (argc < 3){

		std::cerr << "Nope! Usage: " ;
		std::cerr << "<filename1> <filename2> <outputfilename>" << endl;
	return EXIT_FAILURE;
	}

	cout << "number of arguments is : " << argc << endl;

	ApplyRegistration outputReg(argv[1],argv[2],argv[3]);

	outputReg.writeSTL();

	visualizeData visualizer(argv[1], argv[3]);
	visualizer.renderActors();

//	vtkSmartPointer<vtkPolyData> polydata =vtkSmartPointer<vtkPolyData>::New();
//	polydata = meshReader1.getReader()->GetOutput();
//
//	visualizeData showData(polydata);
//
//	showData.renderActors();

	return 0;
}
