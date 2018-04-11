/*
 * visualizeData.cpp
 *
 *  Created on: Apr 4, 2018
 *      Author: richard
 */

#include "visualizeData.h"
#include <vector>

//vtkSmartPointer<vtkPolyData> visualizeData::getPlaneData(vtkSmartPointer<vtkPoints> pPoints,
//											vtkSmartPointer<vtkPoints> nPoints,
//											vtkSmartPointer<vtkXMLPolyDataReader> meshR)
//{
////	  unsigned int numPoints = meshR->GetNumberOfPoints();
////	  unsigned int reducePoints = ceil(numPoints/12);
//
//	  vtkSmartPointer<vtkPolyData> pdata =
//	    vtkSmartPointer<vtkPolyData>::New();
//	  pdata = meshR->GetOutput();
//
//	  unsigned int numPoints = pdata->GetNumberOfPoints();
//	  unsigned int reducePoints = ceil(numPoints/12);
//
//	  std::cout << "Number of points is: " << numPoints << std::endl;
//	  std::cout << "Reduce Points is: " << reducePoints << std::endl;
//
//	  for(vtkIdType i = 0; i < numPoints; i = i + reducePoints){
//
//		  double point1[3];
//		  double point2[3];
//
//		  pdata->GetPoint(i,point1);
//		  pPoints->InsertNextPoint(point1);
//
//		  pdata->GetPoint(i+1,point2);
//		  nPoints->InsertNextPoint(point2);
//
//
//
//	  }
//	  return pdata;
//}
std::vector<vtkSmartPointer<vtkActor> >visualizeData::getArrayCutterActors(
														vtkSmartPointer<vtkPolyData> cData,
														vtkSmartPointer<vtkPolyData> meshData,
														const int nPlanes)
{

	std::cout << "Calculating " << numPlanes << " Planes..." << endl;
	std::vector<vtkSmartPointer<vtkActor> > actors;

	// Create cutter
	unsigned int numPoints = cData->GetNumberOfPoints();
	unsigned int reducepoints = ceil(numPoints/numPlanes);

	for (int i = 0; i < numPoints; i += reducepoints){


		double pPlane[3];
		double pNorm[3];

		cData->GetPoint(i,pPlane);
		cData->GetPoint(i+1,pNorm);

		vtkSmartPointer<vtkPlane> plane =
		vtkSmartPointer<vtkPlane>::New();

		plane->SetOrigin(pPlane[0],pPlane[1],pPlane[2]);
		plane->SetNormal(pNorm[0],pNorm[1],pNorm[2]);

		vtkSmartPointer<vtkCutter> cutter =
		vtkSmartPointer<vtkCutter>::New();
		cutter->SetCutFunction(plane);
		cutter->SetInputData(meshData);
		cutter->Update();

		float pArray[3] = {0,1,0};
		float opac = 1;

		vtkSmartPointer<vtkActor> planeActor = getActor(cutter->GetOutput(),pArray,opac);

		actors.push_back(planeActor);

	}
	std::cout << "Complete calculation of planes ..." << endl;
		return actors;

}

vtkSmartPointer<vtkActor> visualizeData::getActor(vtkSmartPointer<vtkPolyData> data,
												float propArray[], float op){

	vtkSmartPointer<vtkPolyDataMapper> mapper =vtkSmartPointer<vtkPolyDataMapper>::New();

	mapper->SetInputData(data);

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



	std::vector<vtkSmartPointer<vtkActor> > planeActorsYear1 = getArrayCutterActors(centerlineData.getPdata(),
																staticMesh.getPdata(),
																numPlanes);
	std::vector<vtkSmartPointer<vtkActor> > planeActorsYear4 = getArrayCutterActors(centerlineData.getPdata(),
																dynamicMesh.getPdata(),
																numPlanes);

	for(int i =0; i < numPlanes; i++){
		//Set properties on Actors

		renderer->AddActor(planeActorsYear1[i]);
		renderer->AddActor(planeActorsYear4[i]);
	}

	float pArray1[3] = {0.1,0.9,0.9};
	float pArray2[3] = {0.9,0.2,0.1};
	float pArray3[3] = {0.9,0.7,0.8};

	float op1 = 0.6;
	float op2 = 0.3;
	float op3 = 1.0;

	vtkSmartPointer<vtkActor> staticActor = getActor(staticMesh.getPdata(),pArray1,op1);
	vtkSmartPointer<vtkActor> dynamicActor = getActor(dynamicMesh.getPdata(),pArray2,op2);
	vtkSmartPointer<vtkActor> centerlineActor = getActor(centerlineData.getPdata(),pArray3,op3);

	renderer->AddActor(staticActor);
	renderer->AddActor(dynamicActor);
	renderer->AddActor(centerlineActor);

	renWin->AddRenderer(renderer);

	std::cout << "Starting Render Window .... " << std::endl;
	//Render and interact
	renWin->Render();
	iRen->Start();
}
visualizeData::~visualizeData() {
	// TODO Auto-generated destructor stub
}
