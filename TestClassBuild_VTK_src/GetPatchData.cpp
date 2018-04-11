/*
 * GetPatchData.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: richard
 */

#include "GetPatchData.h"
#include "vtkClipPolyData.h"

GetPatchData::GetPatchData(vtkSmartPointer<vtkPolyData> patch,
							vtkSmartPointer<vtkPolyData> staticMesh,
							vtkSmartPointer<vtkPolyData> dynamicMesh,
							vtkSmartPointer<vtkPolyData> centerlineData)
{
	this->patch = patch;
	this->staticMesh = staticMesh;
	this->dynamicMesh = dynamicMesh;
	this->centerlineData = centerlineData;

}
vtkSmartPointer<vtkPolyData> GetPatchData::clipSection(vtkSmartPointer<vtkPolyData> mesh)
{

	// Create criteria for patch
	unsigned int numPoints = centerlineData->GetNumberOfPoints();
	unsigned int reducepoints = ceil(numPoints/numPlanes);
	unsigned int planeStart = reducepoints*6;

	for (int i = planeStart; i <= reducepoints*(6+1); i += reducepoints*(6+1)){


		double pPlane[3];
		double pNorm[3];

		centerlineData->GetPoint(i,pPlane);
		centerlineData->GetPoint(i+1,pNorm);

		vtkSmartPointer<vtkPlane> plane =
		vtkSmartPointer<vtkPlane>::New();

		plane->SetOrigin(pPlane[0],pPlane[1],pPlane[2]);
		plane->SetNormal(pNorm[0],pNorm[1],pNorm[2]);

		vtkSmartPointer<vtkClipPolyData> clipper =
		  vtkSmartPointer<vtkClipPolyData>::New();
		clipper->SetClipFunction(plane);
		clipper->SetInputData(mesh);
		clipper->InsideOutOn();
		clipper->Update();

		float pArray[3] = {0,1,0};
		float opac = 1;

		vtkSmartPointer<vtkActor> planeActor = getActor(cutter->GetOutput(),pArray,opac);

		actors.push_back(planeActor);

	}
	std::cout << "Complete calculation of planes ..." << endl;
		return actors;

}
GetPatchData::~GetPatchData() {
	// TODO Auto-generated destructor stub
}

