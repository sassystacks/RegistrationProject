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
#include "vtkPolyDataNormals.h"

//Personal classes
#include "ReadWriteImg.h"

class VisualizeData
{
private:
	vtkSmartPointer<vtkPolyData> pData;

	vtkSmartPointer<vtkPolyData> staticMesh;
	vtkSmartPointer<vtkPolyData> dynamicMesh;
	vtkSmartPointer<vtkPolyData> centerlineData;


//	ReadWriteImg staticMesh;
//	ReadWriteImg dynamicMesh;
//	ReadWriteImg centerlineData;

	const char* fnameStaticMesh;
	const char* fnameDynamicMesh;
	const char* fnameCenterLineData;

	int numPlanes;

public:
	void renderActors();
	void simpleShowPolyData(vtkSmartPointer<vtkPolyData>);
	void simpleShowPolyData(vtkSmartPointer<vtkPolyData>,vtkSmartPointer<vtkPolyData>);
	vtkSmartPointer<vtkActor> getActor(vtkSmartPointer<vtkPolyData>,float[], float);
	std::vector<vtkSmartPointer<vtkActor> > getArrayCutterActors(vtkSmartPointer<vtkPolyData>,
																vtkSmartPointer<vtkPolyData> ,
																int );
	VisualizeData(vtkSmartPointer<vtkPolyData>,vtkSmartPointer<vtkPolyData>
					,vtkSmartPointer<vtkPolyData>, int);
	void visualizeNormals(vtkPolyData*, vtkPolyDataNormals*);
		//:staticMesh(fnameStaticMesh),
//			dynamicMesh(fnameDynamicMesh),
//			centerlineData(fnameCenterLineData);
//	VisualizeData(const char* fnameStaticMesh, const char* fnameDynamicMesh,
//						const char* fnameCenterLineData, int numPlanes);
//	:staticMesh(fnameStaticMesh),
//	dynamicMesh(fnameDynamicMesh),
//	centerlineData(fnameCenterLineData)
//	{
//		this->fnameStaticMesh = fnameStaticMesh;
//		this->fnameDynamicMesh = fnameDynamicMesh;
//		this->numPlanes = numPlanes;
//		this->fnameCenterLineData = fnameCenterLineData;
//	}
	VisualizeData();
//	{
//		this->pData = pd;
//	}

	virtual ~VisualizeData();
};


#endif /* SOURCE_DIRECTORY__VISUALIZEDATA_H_ */
