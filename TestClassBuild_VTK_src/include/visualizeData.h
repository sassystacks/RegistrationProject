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

//Personal classes
#include "ReadWriteImg.h"

class visualizeData
{
private:
	ReadWriteImg staticMesh;
	ReadWriteImg dynamicMesh;


	const char* fnameStaticMesh;
	const char* fnameDynamicMesh;

public:
	void renderActors();
	vtkSmartPointer<vtkActor> getActor(ReadWriteImg,float[], float);
	visualizeData(const char* fnameStaticMesh, const char* fnameDynamicMesh)
	:staticMesh(fnameStaticMesh)
	,dynamicMesh(fnameDynamicMesh)
	{
		this->fnameStaticMesh = fnameStaticMesh;
		this->fnameDynamicMesh = fnameDynamicMesh;
	};
	virtual ~visualizeData();
};


#endif /* SOURCE_DIRECTORY__VISUALIZEDATA_H_ */
