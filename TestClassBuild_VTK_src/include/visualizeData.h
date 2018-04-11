/*
 * visualizeData.h
 *
 *  Created on: Apr 4, 2018
 *      Author: richard
 */

#ifndef SOURCE_DIRECTORY__VISUALIZEDATA_H_
#define SOURCE_DIRECTORY__VISUALIZEDATA_H_

#include "vtkRenderWindow.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkActor.h"
#include "vtkProperty.h"
#include "vtkRenderer.h"
#include "vtkPolyData.h"
#include "vtkPlane.h"
#include "vtkCutter.h"

//Personal classes
#include "ReadWriteImg.h"

class visualizeData
{
private:
	ReadWriteImg staticMesh;
	ReadWriteImg dynamicMesh;
	ReadWriteImg centerlineData;

	const char* fnameStaticMesh;
	const char* fnameDynamicMesh;
	const char* fnameCenterLineData;

	int numPlanes;

public:
	void renderActors();
	vtkSmartPointer<vtkActor> getActor(vtkSmartPointer<vtkPolyData>,float[], float);
	std::vector<vtkSmartPointer<vtkActor> > getArrayCutterActors(vtkSmartPointer<vtkPolyData>,
																vtkSmartPointer<vtkPolyData> ,
																int );
	visualizeData(const char* fnameStaticMesh, const char* fnameDynamicMesh,
					const char* fnameCenterLineData, int numPlanes)

	:staticMesh(fnameStaticMesh),
	dynamicMesh(fnameDynamicMesh),
	centerlineData(fnameCenterLineData)
	{
		this->fnameStaticMesh = fnameStaticMesh;
		this->fnameDynamicMesh = fnameDynamicMesh;
		this->numPlanes = numPlanes;
		this->fnameCenterLineData = fnameCenterLineData;
	};
	virtual ~visualizeData();
};


#endif /* SOURCE_DIRECTORY__VISUALIZEDATA_H_ */
