/*
 * visualizeData.cpp
 *
 *  Created on: Apr 4, 2018
 *      Author: richard
 */

#include "VisualizeData.h"
#include "vtkArrowSource.h"
#include "vtkGlyph3D.h"
#include "vtkCellCenters.h"
#include <vector>

VisualizeData::VisualizeData(vtkSmartPointer<vtkPolyData> staticMesh,vtkSmartPointer<vtkPolyData> dynamicMesh,
							vtkSmartPointer<vtkPolyData> centerlineData, int numPlanes)

	{
		this->staticMesh = staticMesh;
		this->dynamicMesh = dynamicMesh;
		this->numPlanes = numPlanes;
		this->centerlineData = centerlineData;

//		this->fnameStaticMesh = fnameStaticMesh;
//		this->fnameDynamicMesh = fnameDynamicMesh;
//		this->numPlanes = numPlanes;
//		this->fnameCenterLineData = fnameCenterLineData;
	}
	VisualizeData::VisualizeData()
	{
//		this->staticMesh = staticMesh;
	}
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

std::vector<vtkSmartPointer<vtkActor>> VisualizeData::getArrayCutterActors(
														vtkSmartPointer<vtkPolyData> cData,
														vtkSmartPointer<vtkPolyData> meshData,
														const int nPlanes)
{

	std::cout << "Calculating " << nPlanes << " Planes..." << endl;
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

vtkSmartPointer<vtkActor> VisualizeData::getActor(vtkSmartPointer<vtkPolyData> data,
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


void VisualizeData::renderActors(){
	vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();

	renWin->SetSize(400, 400);
	renWin->SetWindowName("Cell3D Demonstration");

	vtkSmartPointer<vtkRenderWindowInteractor> iRen =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();

	iRen->SetRenderWindow(renWin);

	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();



	std::vector<vtkSmartPointer<vtkActor> > planeActorsYear1 = getArrayCutterActors(centerlineData,
																staticMesh,
																numPlanes);
	std::vector<vtkSmartPointer<vtkActor> > planeActorsYear4 = getArrayCutterActors(centerlineData,
																dynamicMesh,
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

	vtkSmartPointer<vtkActor> staticActor = getActor(staticMesh,pArray1,op1);
	vtkSmartPointer<vtkActor> dynamicActor = getActor(dynamicMesh,pArray2,op2);
	vtkSmartPointer<vtkActor> centerlineActor = getActor(centerlineData,pArray3,op3);

	renderer->AddActor(staticActor);
	renderer->AddActor(dynamicActor);
	renderer->AddActor(centerlineActor);

	renWin->AddRenderer(renderer);

	std::cout << "Starting Render Window .... " << std::endl;
	//Render and interact
	renWin->Render();
	iRen->Start();
}
void VisualizeData::simpleShowPolyData(vtkSmartPointer<vtkPolyData> pdat)
{
	float pArray[3] = {0.9,0.7,0.8};
	float op = 1.0;
	vtkSmartPointer<vtkActor> actor = getActor(pdat,pArray,op);
	vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();

	renWin->SetSize(400, 400);
	renWin->SetWindowName("Simple Render");

	vtkSmartPointer<vtkRenderWindowInteractor> iRen =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();

	iRen->SetRenderWindow(renWin);

	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	renderer->AddActor(actor);
	renWin->AddRenderer(renderer);
	std::cout << "Starting Render Window .... " << std::endl;
	//Render and interact
	renWin->Render();
	iRen->Start();

}
void VisualizeData::simpleShowPolyData(vtkSmartPointer<vtkPolyData> pdat1,
										vtkSmartPointer<vtkPolyData> pdat2){
	float pArray1[3] = {0.1,0.3,0.9};
	float op1 = 1.0;
	float pArray2[3] = {0.9,0.35,0.2};
	float op2 = 1.0;

	vtkSmartPointer<vtkActor> actor1 = getActor(pdat1,pArray1,op1);
	vtkSmartPointer<vtkActor> actor2 = getActor(pdat2,pArray2,op2);

	vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();

	renWin->SetSize(400, 400);
	renWin->SetWindowName("Cell3D Demonstration");

	vtkSmartPointer<vtkRenderWindowInteractor> iRen =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();

	iRen->SetRenderWindow(renWin);

	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();


	renderer->AddActor(actor1);
	renderer->AddActor(actor2);


	renWin->AddRenderer(renderer);

	std::cout << "Starting Render Window .... " << std::endl;
	//Render and interact
	renWin->Render();
	iRen->Start();
}

void VisualizeData::visualizeNormals(vtkPolyData* pdata, vtkPolyDataNormals* pdataNormals) {

	float pArray1[3] = {0.1,0.3,0.9};
	float op1 = 1.0;
	float pArray2[3] = {0.9,0.3,0.1};
	float op2 = 0.3;


	vtkSmartPointer<vtkArrowSource> arrow = vtkSmartPointer<vtkArrowSource>::New();

	arrow->Update();

	vtkSmartPointer<vtkGlyph3D> glyph = vtkSmartPointer<vtkGlyph3D>::New();

	vtkSmartPointer<vtkCellCenters> centers = vtkSmartPointer<vtkCellCenters>::New();
	centers->SetInputConnection(pdataNormals->GetOutputPort());

	centers->Update();

	glyph->SetInputConnection(centers->GetOutputPort());
	glyph->SetSourceData(arrow->GetOutput());
	glyph->SetVectorModeToUseNormal();
	glyph->SetScaleModeToScaleByVector();
	glyph->SetScaleFactor(.01);
	glyph->OrientOn();
	glyph->Update();

	vtkSmartPointer<vtkActor> actor1 = getActor(pdata,pArray1,op1);
	vtkSmartPointer<vtkActor> actor2 = getActor(glyph->GetOutput(),pArray2,op2);
	vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();

	renWin->SetSize(400, 400);
	renWin->SetWindowName("Cell3D Demonstration");

	vtkSmartPointer<vtkRenderWindowInteractor> iRen =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();

	iRen->SetRenderWindow(renWin);

	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	renderer->AddActor(actor1);
	renderer->AddActor(actor2);

	renWin->AddRenderer(renderer);

	std::cout << "Starting Render Window .... " << std::endl;
	//Render and interact
	renWin->Render();
	iRen->Start();
}

VisualizeData::~VisualizeData() {
	// TODO Auto-generated destructor stub
}
