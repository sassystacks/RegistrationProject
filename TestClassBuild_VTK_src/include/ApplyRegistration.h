/*
 * ApplyRegistration.h
 *
 *  Created on: Apr 5, 2018
 *      Author: richard
 */

#ifndef SOURCE_DIRECTORY__INCLUDE_APPLYREGISTRATION_H_
#define SOURCE_DIRECTORY__INCLUDE_APPLYREGISTRATION_H_

#include "itkMesh.h"
#include "itkMeshFileReader.h"
#include "itkMeshFileWriter.h"
#include "itkQuadEdgeMesh.h"
#include "itkSTLMeshIOFactory.h"
#include "itkSTLMeshIO.h"
#include "itkQuadEdgeMeshDecimationCriteria.h"
#include "itkSquaredEdgeLengthDecimationQuadEdgeMeshFilter.h"
#include "itkEuler3DTransform.h"
#include "itkEuclideanDistancePointMetric.h"
#include "itkLevenbergMarquardtOptimizer.h"
#include "itkPointSetToPointSetRegistrationMethod.h"
#include "itkTransformMeshFilter.h"

//Other C++
#include "math.h"
#include <iostream>

class ApplyRegistration {
private:
	const char *fnameStaticMesh;
	const char *fnameDynamicMesh;
	const char *fnameOutputMesh;

public:

	int writeSTL();
	ApplyRegistration(const char *,const char *,const char *);
	virtual ~ApplyRegistration();
};

#endif /* SOURCE_DIRECTORY__INCLUDE_APPLYREGISTRATION_H_ */
