/*
 * MaterialProperties.h
 *
 *  Created on: Apr 10, 2018
 *      Author: richard
 */

#ifndef MATERIALPROPERTIES_H_
#define MATERIALPROPERTIES_H_

#include "vtkPolyData.h"
#include "vtkMassProperties.h"

class MaterialProperties {

private:

	vtkSmartPointer<vtkPolyData> mesh;

public:

	vtkSmartPointer<vtkMassProperties> setMass();
	double normalizeDeltaVolume(double, double);
	MaterialProperties(vtkSmartPointer<vtkPolyData>);
	virtual ~MaterialProperties();
};

#endif /* MATERIALPROPERTIES_H_ */
