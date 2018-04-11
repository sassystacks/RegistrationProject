/*
 * GetPatchData.h
 *
 *  Created on: Apr 10, 2018
 *      Author: richard
 */

#ifndef GETPATCHDATA_H_
#define GETPATCHDATA_H_

#include "vtkPolyData.h"

class GetPatchData {

private:
	vtkSmartPointer<vtkPolyData> patch;

	vtkSmartPointer<vtkPolyData> staticMesh;
	vtkSmartPointer<vtkPolyData> dynamicMesh;
	vtkSmartPointer<vtkPolyData> centerlineData;

public:
	GetPatchData(vtkSmartPointer<vtkPolyData>,
			vtkSmartPointer<vtkPolyData>,
			vtkSmartPointer<vtkPolyData>,
			vtkSmartPointer<vtkPolyData>);
	vtkSmartPointer<vtkPolyData> clipSection(vtkSmartPointer<vtkPolyData>);
	double calcVolume();
	double calcDeltaVolume();

	virtual ~GetPatchData();
};

#endif /* GETPATCHDATA_H_ */
