/*
 * GetPatchData.h
 *
 *  Created on: Apr 10, 2018
 *      Author: richard
 */

#ifndef PATCHDATA_H_
#define PATCHDATA_H_

#include "vtkPolyData.h"
#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkFloatArray.h>
#include <vtkPoints.h>
#include <vtkPolyDataNormals.h>
#include <vtkPointData.h>
#include <vtkSmartPointer.h>

class PatchData {

private:
	vtkSmartPointer<vtkPolyData> patch;

	vtkSmartPointer<vtkPolyData> staticMesh;
	vtkSmartPointer<vtkPolyData> centerlineData;
	int patchMin;
	int patchMax;
	int numPlanes;

	vtkSmartPointer<vtkFloatArray> patchFarray;
	vtkSmartPointer<vtkDoubleArray> patchDarray;
	vtkSmartPointer<vtkPolyDataNormals> pointNormals;
	vtkSmartPointer<vtkPolyDataNormals> cellNormals;

public:
	PatchData(vtkSmartPointer<vtkPolyData>,
				vtkSmartPointer<vtkPolyData>,
				int,int,int);

	vtkSmartPointer<vtkPolyData> clipSection(vtkSmartPointer<vtkPolyData>);
	vtkSmartPointer<vtkPolyData> closePatch(vtkSmartPointer<vtkPolyData>);
	void getCellNormals(vtkPolyData*);
	void getPointNormals(vtkPolyData*);
	void setNormalDoubleArray(vtkDoubleArray* darray){patchDarray=darray;}
	void setNormalFloatArray(vtkFloatArray* farray){patchFarray=farray;}
	void setPointNormals(vtkSmartPointer<vtkPolyDataNormals> pNorms){pointNormals = pNorms;}
	void setCellNormals(vtkSmartPointer<vtkPolyDataNormals> cNorms){cellNormals = cNorms;}
	bool isPointNormals(vtkPolyData*);
	bool isCellNormals(vtkPolyData*);


	virtual ~PatchData();
};

#endif /* PATCHDATA_H_ */