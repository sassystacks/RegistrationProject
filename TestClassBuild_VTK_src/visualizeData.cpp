/*
 * visualizeData.cpp
 *
 *  Created on: Apr 4, 2018
 *      Author: richard
 */

#include "visualizeData.h"

//visualizeData::visualizeData(const char* staticMeshFname,
//							const char* dynamicMeshFname,
//							const char* centerLineMeshFname)
//:staticMesh(staticMeshFname)
//	 ,dynamicMesh(dynamicMeshFname)
//	 ,centerLineMesh(centerLineMeshFname)
//
//{
//
//	this-> staticMeshFname = staticMeshFname;
//	this-> dynamicMeshFname = dynamicMeshFname;
//	this-> centerLineMeshFname = centerLineMeshFname;
//
//}

//std::vector<vtkSmartPointer<vtkActor> >visualizeData::getArrayCutterActors(vtkSmartPointer<vtkPoints> pPoints,
//											vtkSmartPointer<vtkPoints> nPoints,
//											vtkSmartPointer<vtkSTLReader> meshR,
//											vtkSmartPointer<vtkXMLPolyDataReader> polyR,
//											int numPlanes)
//{
//	std::cout << "Calculating " << numPlanes << " Planes..." << endl;
//	std::vector<vtkSmartPointer<vtkActor> > actors;
//	// Create cutter
//
//	vtkSmartPointer<vtkPolyData> pdata =
//	vtkSmartPointer<vtkPolyData>::New();
//	pdata = polyR->GetOutput();
//
//	unsigned int numPoints = pdata->GetNumberOfPoints();
//	unsigned int reducepoints = ceil(numPoints/numPlanes);
//
//	for (int i = 0; i < numPoints; i += reducepoints){
//
//
//		double pPlane[3];
//		double pNorm[3];
//
//		pdata->GetPoint(i,pPlane);
//		pdata->GetPoint(i+1,pNorm);
//
//		vtkSmartPointer<vtkPlane> plane =
//		vtkSmartPointer<vtkPlane>::New();
//
//		plane->SetOrigin(pPlane[0],pPlane[1],pPlane[2]);
//		plane->SetNormal(pNorm[0],pNorm[1],pNorm[2]);
//
//		vtkSmartPointer<vtkCutter> cutter =
//		vtkSmartPointer<vtkCutter>::New();
//		cutter->SetCutFunction(plane);
//		cutter->SetInputConnection(meshR->GetOutputPort());
//		cutter->Update();
//
//		vtkSmartPointer<vtkActor> planeActor = getActorFromPoly(cutter->GetOutput());
//
//		actors.push_back(planeActor);
//
//	}
//	std::cout << "Complete calculation of planes ..." << endl;
//		return actors;
//
//}

vtkSmartPointer<vtkActor> visualizeData::getActor(ReadWriteImg data,
												float propArray[], float op){

	vtkSmartPointer<vtkPolyDataMapper> mapper =vtkSmartPointer<vtkPolyDataMapper>::New();

	mapper->SetInputData(data.getReader()->GetOutput());

	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

	//properties
	vtkSmartPointer<vtkProperty> prop = vtkSmartPointer<vtkProperty>::New();

	prop -> SetColor(propArray[0],propArray[1],propArray[2]);
	prop -> SetOpacity(op);

	actor -> SetMapper(mapper);
	actor -> SetProperty(prop);

	return actor;
}
void visualizeData::renderActors(){
	vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();



		renWin->SetSize(400, 400);
		renWin->SetWindowName("Cell3D Demonstration");

		vtkSmartPointer<vtkRenderWindowInteractor> iRen =
				vtkSmartPointer<vtkRenderWindowInteractor>::New();

		iRen->SetRenderWindow(renWin);

		vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

		float pArray1[3] = {0.1,0.9,0.9};
		float pArray2[3] = {0.9,0.2,0.1};

		float op1 = 0.6;
		float op2 = 0.3;

		vtkSmartPointer<vtkActor> staticActor = getActor(staticMesh,pArray1,op1);
		vtkSmartPointer<vtkActor> dynamicActor = getActor(dynamicMesh,pArray2,op2);

		renderer->AddActor(staticActor);
		renderer->AddActor(dynamicActor);

		renWin->AddRenderer(renderer);

		std::cout << "Starting Render Window .... " << std::endl;
		//Render and interact
		renWin->Render();
		iRen->Start();
}
visualizeData::~visualizeData() {
	// TODO Auto-generated destructor stub
}
