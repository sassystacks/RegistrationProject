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
#include "vtkIdList.h"
#include "vtkCellCenters.h"
#include "vtkCellLocator.h"
#include "vtkMath.h"


//remove this
#include "VisualizeData.h"

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
void PatchData::PointNormals(vtkPolyData* polydata)
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
vtkSmartPointer<vtkPolyDataNormals> PatchData::calcNormals(vtkPolyData* polydata)
{
	vtkSmartPointer<vtkPolyDataNormals> normalGenerator = vtkSmartPointer<vtkPolyDataNormals>::New();

	    normalGenerator->SetInputData(polydata);
	    normalGenerator->ComputePointNormalsOff();
	    normalGenerator->ComputeCellNormalsOn();
	    normalGenerator->Update();

	    return normalGenerator;
}

void PatchData::CellNormals(vtkPolyData* polydata)
{
  // Try to read normals directly
  bool hasCellNormals = isCellNormals(polydata);

  if(!hasCellNormals)
    {
    std::cout << "Computing normals..." << std::endl;

    // Generate normals
    vtkSmartPointer<vtkPolyDataNormals> normalGen= vtkSmartPointer<vtkPolyDataNormals>::New();
    normalGen = calcNormals(polydata);
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

    polydata = normalGen->GetOutput();
    // Try to read normals again
    hasCellNormals = isCellNormals(polydata);

    std::cout << "On the second try, has cell normals? " << hasCellNormals << std::endl;

//    setCellNormals(normalGen);

    }
  else
    {
    std::cout << "Cell normals were found!" << std::endl;
    }



}
void PatchData::setCellntersectData(vtkPolyData* pdataReference, vtkPolyData* pdataCurrent)
{
	vtkSmartPointer<vtkPolyData> copyRef =
					    vtkSmartPointer<vtkPolyData>::New();

	//Copy Reference Polydata to apply scalars later
	copyRef->DeepCopy(pdataReference);

	vtkSmartPointer<vtkPolyDataNormals> norms =
				    vtkSmartPointer<vtkPolyDataNormals>::New();

	 //Try to read normals directly
	 bool hasCellNormals = isCellNormals(pdataReference);

	//Check if the polydata has normals
	if(!hasCellNormals)

	{
		std::cout << "No Normals Found ..." << std::endl;
		norms = calcNormals(pdataReference);

	}

	else
	{
		std::cout << "Normals Found ..." << std::endl;
		norms->SetInputData(pdataReference);
	}

	//flip Normals to point toward the current configuration
	norms->FlipNormalsOn();
	norms->Update();

	//Get the centers of the reference configuration cells
	vtkSmartPointer<vtkCellCenters> centersRef = vtkSmartPointer<vtkCellCenters>::New();

	centersRef->SetInputConnection(norms->GetOutputPort());
	centersRef->Update();

	//Get the array of all the normals for the reference configuration
	vtkSmartPointer<vtkFloatArray> normalArray =
		vtkFloatArray::SafeDownCast(norms->GetOutput()->GetCellData()->GetNormals());

	//id list to store the centers being used to calculate the deformation
	vtkSmartPointer<vtkIdList> ids =
			vtkSmartPointer<vtkIdList>::New();

	//build cell locator
	vtkSmartPointer<vtkCellLocator> locator =
			vtkSmartPointer<vtkCellLocator>::New();

	//Add the current Configuration to the cell locator
	locator->SetDataSet(pdataCurrent);
	locator->BuildLocator();

	//initialize cell centers for the current configuration
	vtkSmartPointer<vtkCellCenters> centers_Current = vtkSmartPointer<vtkCellCenters>::New();

	//set the current configuration to the cell centers
	centers_Current->SetInputData(pdataCurrent);
	centers_Current->Update();

	vtkSmartPointer<vtkFloatArray> scalars =
	    vtkSmartPointer<vtkFloatArray>::New();

	scalars->SetNumberOfValues(normalArray->GetNumberOfTuples());
	//set tolerance for finding cells on line
	double tolerance = 0.0;

	//this will be checked in each iteration to determine the range of scalars
	double maxDistance = 0.0;

	//For loop to find all cells that have a normal intersection with the current configuration
	for (vtkIdType i = 0; i<normalArray->GetNumberOfTuples(); i++)
	{
		//Create Arrays to store data in each loop
		double normArray[3];
		double pCenter[3];
		double pNorm[3];
		double pCurrent[3];
		double scalarParam = 0.05;

		//get the centers of the reference configuration
		centersRef->GetOutput()->GetPoint(i,pCenter);

		//Get the array describing the normal direction from the cell
		normalArray->GetTuple(i,normArray);

		//Use the relationship t*(l,m,n)=(x_1-x0,y_1-y_0,z_1-z_0) to get second point on the line
		pNorm[0] = pCenter[0] + normArray[0]*scalarParam;
		pNorm[1] = pCenter[1] + normArray[1]*scalarParam;
		pNorm[2] = pCenter[2] + normArray[2]*scalarParam;

		//Find the cells that intersect with the line
		locator->FindCellsAlongLine(pCenter,pNorm,tolerance,ids);


		//		  std::cout << "The center is: " << pCenter[0] << "," << pCenter[1]
		//					<< "," << pCenter[2] << std::endl;

		//distance total will be the average of all distances found in the calculation
		double distanceTotal=0;

		//loop through all of the ids that intersected with the normal line
		for(vtkIdType k = 0; k < ids->GetNumberOfIds(); k++)
		{
			//get the center point of the current configuration
			centers_Current->GetOutput()->GetPoint(k,pCurrent);

			//find the distance from one configuration to the other
			double squaredDistance = vtkMath::Distance2BetweenPoints(pCenter, pCurrent);

			// Take the square root to get the Euclidean distance between the points.
			double distance = sqrt(squaredDistance);

			if (distance>maxDistance)
			{
				maxDistance=distance;
			}

			//Get the average distance from each point to the reference configuration
			distanceTotal = float((distanceTotal+distance)/(k+1));

			//std::cout << "the distance at " << ids->GetId(k) << " id found was : " << distance << std::endl;
		}

	//Add the new distance to the double array for scalars
	scalars->SetValue(i,distanceTotal);

	}

	//Set the scalar values to the cells in the reference configuration
	copyRef->GetCellData()->SetScalars(scalars);

	//set the polyData
	setDeformationData(copyRef);

	//Set the maximum distance value for the range of deformation
	setDeformationMax((float)maxDistance);

	std::cout << "The maximimum deformed distance was: " << maxDistance << std::endl;

	//remove later ~~~~~~~ Visualize the output of this function
	VisualizeData Test;

	Test.visualizeDeformationData(copyRef,maxDistance);
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

