/*
 * MaterialProperties.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: richard
 */

#include "MaterialProperties.h"
#include "vtkMassProperties.h"
#include <cmath>

MaterialProperties::MaterialProperties(vtkSmartPointer<vtkPolyData> mesh) {

	this->mesh=mesh;

}

vtkSmartPointer<vtkMassProperties> MaterialProperties::setMass(){
	vtkSmartPointer<vtkMassProperties> mass = vtkSmartPointer<vtkMassProperties>::New();

	mass->SetInputData(mesh);
	mass->Update();

	return mass;

}

double MaterialProperties::normalizeDeltaVolume(double vol1, double vol2)
{
	return abs((vol2-vol1)/vol1);

}


MaterialProperties::~MaterialProperties() {
	// TODO Auto-generated destructor stub
}

