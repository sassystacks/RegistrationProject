// VTK
#include "vtkProperty.h"
#include "vtkVersion.h"
#include <vtkCellArray.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCamera.h>
#include <vtkSTLReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyData.h>
#include "itkVTKPolyDataReader.h"

#include <iostream>

int main( int argc, char* argv[] ){


	//
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~ VTK Visualization ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	if (argc < 3){

		std::cerr << "Nope! Usage: " ;
		std::cerr << "<filename1> <filename2>" << endl;
	}

	std::cout << "Starting Visualization ....... " << std::endl;

	vtkSmartPointer<vtkSTLReader> meshReader1 = vtkSmartPointer<vtkSTLReader>::New();
	meshReader1->SetFileName(argv[1]);
	meshReader1->Update();

	vtkSmartPointer<vtkSTLReader> meshReader2 = vtkSmartPointer<vtkSTLReader>::New();
	meshReader2->SetFileName(argv[2]);
	meshReader2->Update();

	vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();

	renWin->SetSize(400, 400);
	renWin->SetWindowName("Cell3D Demonstration");

	vtkSmartPointer<vtkRenderWindowInteractor> iRen =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();

	iRen->SetRenderWindow(renWin);

	  vtkSmartPointer<vtkPolyDataMapper> mapper1 =vtkSmartPointer<vtkPolyDataMapper>::New();
	  vtkSmartPointer<vtkPolyDataMapper> mapper2 =vtkSmartPointer<vtkPolyDataMapper>::New();

	  mapper1->SetInputConnection(meshReader1->GetOutputPort());
	  mapper2->SetInputConnection(meshReader2->GetOutputPort());

	vtkSmartPointer<vtkActor> actor1 = vtkSmartPointer<vtkActor>::New();
	vtkSmartPointer<vtkActor> actor2 = vtkSmartPointer<vtkActor>::New();

	//properties
	vtkSmartPointer<vtkProperty> prop1 = vtkSmartPointer<vtkProperty>::New();
	vtkSmartPointer<vtkProperty> prop2 = vtkSmartPointer<vtkProperty>::New();

	//Set Properties
	prop1 -> SetColor(0.9,0.2,0.1);
	prop1 -> SetOpacity(0.3);

	prop2 -> SetColor(0.1,0.2,0.9);
	prop2 -> SetOpacity(1);


	actor1 -> SetMapper(mapper1);
	actor1 -> SetProperty(prop1);

	actor2 -> SetMapper(mapper2);
	actor2 -> SetProperty(prop2);

	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	renderer->AddActor(actor1);
	renderer->AddActor(actor2);

	renWin->AddRenderer(renderer);

	std::cout << "Starting Render Window .... " << std::endl;
	//Render and interact
	renWin->Render();
	iRen->Start();

	return 0;

}
