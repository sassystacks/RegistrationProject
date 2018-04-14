/*
 * GetPatchData.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: richard
 */

#include "PatchData.h"

#include "vtkPlane.h"
#include "vtkClipPolyData.h"
#include "vtkFillHolesFilter.h"
#include "vtkPolyDataNormals.h"

#include <iostream>
#include <vector>

PatchData::PatchData(
							vtkSmartPointer<vtkPolyData> staticMesh,
							vtkSmartPointer<vtkPolyData> centerlineData,
							int patchMin, int patchMax, int numPlanes)
{

	this->staticMesh = staticMesh;
	this->centerlineData = centerlineData;

	this->patchMin = patchMin;
	this->patchMax = patchMax;
	this->numPlanes = numPlanes;

	std::cout << "Patch data initialized ..." << std::endl;
}
vtkSmartPointer<vtkPolyData> PatchData::closePatch(vtkSmartPointer<vtkPolyData> pdata){

	vtkSmartPointer<vtkFillHolesFilter> hFilter = vtkSmartPointer<vtkFillHolesFilter>::New();
	vtkSmartPointer<vtkPolyData> copy = vtkSmartPointer<vtkPolyData>::New();

	copy->DeepCopy(pdata);

	hFilter->SetInputData(copy);

	std::cout << "Maximum hole size to fill is: " << hFilter->GetHoleSize() << std::endl;

	  vtkSmartPointer<vtkPolyDataNormals> normals =
	    vtkSmartPointer<vtkPolyDataNormals>::New();
	  normals->SetInputConnection(hFilter->GetOutputPort());
	  normals->ConsistencyOn();
	  normals->SplittingOff();
	  normals->Update();
	return normals->GetOutput();


}
bool PatchData::isPointNormals(vtkPolyData* polydata)
{
  std::cout << "In GetPointNormals: " << polydata->GetNumberOfPoints() << std::endl;
  std::cout << "Looking for point normals..." << std::endl;

  // Count points
  vtkIdType numPoints = polydata->GetNumberOfPoints();
  std::cout << "There are " << numPoints << " points." << std::endl;

  // Count triangles
  vtkIdType numPolys = polydata->GetNumberOfPolys();
  std::cout << "There are " << numPolys << " polys." << std::endl;

  // Double normals in an array
  vtkDoubleArray* normalDataDouble =
    vtkDoubleArray::SafeDownCast(polydata->GetPointData()->GetArray("Normals"));

  if(normalDataDouble)
    {
    int nc = normalDataDouble->GetNumberOfTuples();
    std::cout << "There are " << nc
            << " components in normalDataDouble" << std::endl;
    return true;
    }
}
bool PatchData::isCellNormals(vtkPolyData* polydata)
{
  std::cout << "Looking for cell normals..." << std::endl;

  // Count points
  vtkIdType numCells = polydata->GetNumberOfCells();
  std::cout << "There are " << numCells << " cells." << std::endl;

  // Count triangles
  vtkIdType numPolys = polydata->GetNumberOfPolys();
  std::cout << "There are " << numPolys << " polys." << std::endl;

  // Double normals in an array
  vtkDoubleArray* normalDataDouble =
    vtkDoubleArray::SafeDownCast(polydata->GetCellData()->GetArray("Normals"));

  if(normalDataDouble)
    {
    int nc = normalDataDouble->GetNumberOfTuples();
    std::cout << "There are " << nc
            << " components in normalDataDouble" << std::endl;

    return true;
    }

  // Double normals in an array
  vtkFloatArray* normalDataFloat =
    vtkFloatArray::SafeDownCast(polydata->GetCellData()->GetArray("Normals"));

  if(normalDataFloat)
    {
    int nc = normalDataFloat->GetNumberOfTuples();
    std::cout << "There are " << nc
            << " components in normalDataFloat" << std::endl;

    setNormalFloatArray(normalDataFloat);

    return true;
    }

  // Point normals
  vtkDoubleArray* normalsDouble =
    vtkDoubleArray::SafeDownCast(polydata->GetCellData()->GetNormals());

  if(normalsDouble)
    {
    std::cout << "There are " << normalsDouble->GetNumberOfComponents()
              << " components in normalsDouble" << std::endl;
    return true;
    }

  ////////////////////////////////////////////////////////////////
  // Point normals
  vtkFloatArray* normalsFloat =
    vtkFloatArray::SafeDownCast(polydata->GetCellData()->GetNormals());

  if(normalsFloat)
    {
    std::cout << "There are " << normalsFloat->GetNumberOfComponents()
              << " components in normalsFloat" << std::endl;
    return true;
    }

  /////////////////////////////////////////////////////////////////////
  // Generic type point normals
  vtkDataArray* normalsGeneric = polydata->GetCellData()->GetNormals(); //works
  if(normalsGeneric)
    {
    std::cout << "There are " << normalsGeneric->GetNumberOfTuples()
              << " normals in normalsGeneric" << std::endl;

    double testDouble[3];
    normalsGeneric->GetTuple(0, testDouble);

    std::cout << "Double: " << testDouble[0] << " "
              << testDouble[1] << " " << testDouble[2] << std::endl;

    return true;
    }


  // If the function has not yet quit, there were none of these types of normals
  std::cout << "Normals not found!" << std::endl;
  return false;

}
void PatchData::getPointNormals(vtkPolyData* polydata)
{
  std::cout << "In TestPointNormals: " << polydata->GetNumberOfPoints() << std::endl;
  // Try to read normals directly
  bool hasPointNormals = isPointNormals(polydata);

  if(!hasPointNormals)
    {
    std::cout << "No point normals were found. Computing normals..." << std::endl;

    // Generate normals
    vtkSmartPointer<vtkPolyDataNormals> normalGenerator = vtkSmartPointer<vtkPolyDataNormals>::New();

    normalGenerator->SetInputData(polydata);
    normalGenerator->ComputePointNormalsOn();
    normalGenerator->ComputeCellNormalsOff();
    normalGenerator->Update();
    /*
    // Optional settings
    normalGenerator->SetFeatureAngle(0.1);
    normalGenerator->SetSplitting(1);
    normalGenerator->SetConsistency(0);
    normalGenerator->SetAutoOrientNormals(0);
    normalGenerator->SetComputePointNormals(1);
    normalGenerator->SetComputeCellNormals(0);
    normalGenerator->SetFlipNormals(0);
    normalGenerator->SetNonManifoldTraversal(1);
    */

    polydata = normalGenerator->GetOutput();

    setPointNormals(normalGenerator);

    // Try to read normals again
    hasPointNormals = isPointNormals(polydata);

    std::cout << "On the second try, has point normals? " << hasPointNormals << std::endl;

    setPointNormals(normalGenerator);

    }
  else
    {
    std::cout << "Point normals were found!" << std::endl;
    }
}


void PatchData::getCellNormals(vtkPolyData* polydata)
{
  // Try to read normals directly
  bool hasCellNormals = isCellNormals(polydata);

  if(!hasCellNormals)
    {
    std::cout << "Computing normals..." << std::endl;

    // Generate normals
    vtkSmartPointer<vtkPolyDataNormals> normalGenerator = vtkSmartPointer<vtkPolyDataNormals>::New();
#if VTK_MAJOR_VERSION <= 5
    normalGenerator->SetInput(polydata);
#else
    normalGenerator->SetInputData(polydata);
#endif
    normalGenerator->ComputePointNormalsOff();
    normalGenerator->ComputeCellNormalsOn();
    normalGenerator->Update();
    /*
    // Optional settings
    normalGenerator->SetFeatureAngle(0.1);
    normalGenerator->SetSplitting(1);
    normalGenerator->SetConsistency(0);
    normalGenerator->SetAutoOrientNormals(0);
    normalGenerator->SetComputePointNormals(1);
    normalGenerator->SetComputeCellNormals(0);
    normalGenerator->SetFlipNormals(0);
    normalGenerator->SetNonManifoldTraversal(1);
    */

    polydata = normalGenerator->GetOutput();
    // Try to read normals again
    hasCellNormals = isCellNormals(polydata);

    std::cout << "On the second try, has cell normals? " << hasCellNormals << std::endl;

    setCellNormals(normalGenerator);

    }
  else
    {
    std::cout << "Cell normals were found!" << std::endl;
    }



}

vtkSmartPointer<vtkPolyData> PatchData::clipSection(vtkSmartPointer<vtkPolyData> pdata)
{
	std::cout << "Clipping Data set ..." << std::endl;
	vtkSmartPointer<vtkPolyData> clippedMesh = vtkSmartPointer<vtkPolyData>::New();

	clippedMesh->DeepCopy(pdata);

	vtkSmartPointer<vtkClipPolyData> clipper1 = vtkSmartPointer<vtkClipPolyData>::New();
	vtkSmartPointer<vtkClipPolyData> clipper2 = vtkSmartPointer<vtkClipPolyData>::New();

	// Create criteria for patch
	unsigned int numPoints = centerlineData->GetNumberOfPoints();
	unsigned int reducepoints = ceil(numPoints/numPlanes);
	unsigned int planeStart = reducepoints*patchMin;

	for (int i = planeStart; i <= reducepoints*(patchMax); i += reducepoints){

		std::cout << "Loop Number: " << i << std::endl;

		double pPlane[3];
		double pNorm[3];

		centerlineData->GetPoint(i,pPlane);
		centerlineData->GetPoint(i+1,pNorm);

		vtkSmartPointer<vtkPlane> plane =
		vtkSmartPointer<vtkPlane>::New();

		plane->SetOrigin(pPlane[0],pPlane[1],pPlane[2]);
		plane->SetNormal(pNorm[0],pNorm[1],pNorm[2]);



		if (i == planeStart){
			clipper1->SetClipFunction(plane);
			clipper1->InsideOutOff();
			clipper1->SetInputData(clippedMesh);
			clipper1->Update();

			std::cout <<"clipping bottom"<< endl;
		}
		else{
			clipper2->SetClipFunction(plane);
			clipper2->InsideOutOn();
			clipper2->SetInputData(clipper1->GetOutput());
			clipper2->Update();

			std::cout <<"clipping Top"<< endl;
		}

	}

	std::cout << clipper2->GetOutput()->GetNumberOfPoints() << std::endl;
	return clipper2->GetOutput();

}
PatchData::~PatchData() {
	// TODO Auto-generated destructor stub
}

