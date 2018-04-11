#include <iostream>
#include "ReadWriteImg.h"
#include "visualizeData.h"
#include "ApplyRegistration.h"

using namespace std;

int main( int argc, char* argv[] ){

	if (argc < 5){

		std::cerr << "Nope! Usage: " ;
		std::cerr << "<filename_Static> <filename_Dynamic> <filename_centerline> <outputfilename>" << endl;
	return EXIT_FAILURE;
	}

	cout << "number of arguments is : " << argc << endl;

	ApplyRegistration outputReg(argv[1],argv[2],argv[4]);

	outputReg.writeSTL();

	int nPlanes = 12;

	//visualize the results
	//input : filename_StaticMesh, filenames_outputfile, filename_centerline
	visualizeData visualizer(argv[1],argv[4],argv[3],nPlanes);

	visualizer.renderActors();
//
//	ReadWriteImg img(argv[4]);


	return 0;
}
