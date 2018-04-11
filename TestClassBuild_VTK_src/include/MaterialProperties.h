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
	vtkSmartPointer<vtkMassProperties> massProps;

public:


	MaterialProperties();
	virtual ~MaterialProperties();
};

#endif /* MATERIALPROPERTIES_H_ */
