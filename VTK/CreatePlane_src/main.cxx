#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkActor.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPlaneSource.h>
#include <vtkProperty.h>
#include <vtkSTLReader.h>
#include <vtkIntersectionPolyDataFilter.h>

//Project Headers


//Function Declarations
vtkSmartPointer<vtkPolyData> getPlaneData(vtkSmartPointer<vtkPoints>,
										vtkSmartPointer<vtkPoints>,
										vtkSmartPointer<vtkXMLPolyDataReader>);

vtkSmartPointer<vtkPolyData> getPlane(vtkSmartPointer<vtkPoints>,
							vtkSmartPointer<vtkPoints>,int );

vtkSmartPointer<vtkActor> getActorFromPoly(vtkSmartPointer<vtkPolyData>);

int main(int argc, char *argv[])
{
	if (argc < 3){

		std::cerr << "Nope! Usage: " ;
		std::cerr << "<STL filename1> <VTP filename1>" << endl;
		return EXIT_FAILURE;
	}

	vtkSmartPointer<vtkSTLReader> meshReader = vtkSmartPointer<vtkSTLReader>::New();
	meshReader->SetFileName(argv[1]);
	meshReader->Update();

	// Read data from Centerline file
	vtkSmartPointer<vtkXMLPolyDataReader> polyReader =
	vtkSmartPointer<vtkXMLPolyDataReader>::New();
	polyReader->SetFileName(argv[2]);
	polyReader->Update();


//~~~~~~~~~~~~~~~~~~ Get points to define plane ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Points to place the plane
	vtkSmartPointer<vtkPoints> planePoints= vtkSmartPointer<vtkPoints>::New();

	//describe normal vector to the plane
	vtkSmartPointer<vtkPoints> normPoints= vtkSmartPointer<vtkPoints>::New();

	//Function defined below to obtain center and normal points for plane
	vtkSmartPointer<vtkPolyData> polydata = getPlaneData(planePoints, normPoints, polyReader);

//~~~~~~~~~~~~~~~~~~~~~~~~~~ Define Plane ~~~~~~~~~~~~~~~~~~~~~~

	//Return Plane Source
	int r = 6;
	vtkSmartPointer<vtkPolyData> plane = getPlane(planePoints,normPoints,r);

//~~~~~~~~~~~~~~~~~~~~~~~~~ Render centerline and Plane ~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Get intersection of plane and mesh
	vtkSmartPointer<vtkIntersectionPolyDataFilter> intersection =
	vtkSmartPointer<vtkIntersectionPolyDataFilter>::New();
	intersection->SetInputData( 0, plane);
	intersection->SetInputData( 1, meshReader->GetOutput());
	intersection->Update();

	//Get Actors
	vtkSmartPointer<vtkActor> centerLineActor = getActorFromPoly(polydata);
	vtkSmartPointer<vtkActor> planeActor = getActorFromPoly(plane);
	vtkSmartPointer<vtkActor> meshActor = getActorFromPoly(meshReader->GetOutput());
	vtkSmartPointer<vtkActor> intersectionActor = getActorFromPoly(intersection->GetOutput());



	//Set properties on Actors
	planeActor->GetProperty()->SetColor(0,1,0);
	planeActor->GetProperty()->SetOpacity(1);

	meshActor->GetProperty()->SetColor(0.8,0.1,0.2);
	meshActor->GetProperty()->SetOpacity(0.3);

	// Create a renderer, render window, and interactor
	vtkSmartPointer<vtkRenderer> renderer =
	vtkSmartPointer<vtkRenderer>::New();

	vtkSmartPointer<vtkRenderWindow> renderWindow =
	vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);

	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
	vtkSmartPointer<vtkRenderWindowInteractor>::New();

	renderWindowInteractor->SetRenderWindow(renderWindow);
  
	// Add the actor to the scene
	renderer->AddActor(centerLineActor);
	renderer->AddActor(planeActor);
	renderer->AddActor(meshActor);
	renderer->AddActor(intersectionActor);

	// Render and interact
	renderWindow->Render();
	renderWindowInteractor->Start();
	return EXIT_SUCCESS;
}

//~~~~~~~~~~~~~~~~~~~~~~~ Function Definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

vtkSmartPointer<vtkPolyData> getPlaneData(vtkSmartPointer<vtkPoints> pPoints,
											vtkSmartPointer<vtkPoints> nPoints,
											vtkSmartPointer<vtkXMLPolyDataReader> meshR)
{
//	  unsigned int numPoints = meshR->GetNumberOfPoints();
//	  unsigned int reducePoints = ceil(numPoints/12);

	  vtkSmartPointer<vtkPolyData> pdata =
	    vtkSmartPointer<vtkPolyData>::New();
	  pdata = meshR->GetOutput();

	  unsigned int numPoints = pdata->GetNumberOfPoints();
	  unsigned int reducePoints = ceil(numPoints/12);

	  std::cout << "Number of points is: " << numPoints << std::endl;
	  std::cout << "Reduce Points is: " << reducePoints << std::endl;

	  for(vtkIdType i = 0; i < numPoints; i = i + reducePoints){

		  double point1[3];
		  double point2[3];

		  pdata->GetPoint(i,point1);
		  pPoints->InsertNextPoint(point1);

		  pdata->GetPoint(i+1,point2);
		  nPoints->InsertNextPoint(point2);



	  }
	  return pdata;
}

//Get a plane
vtkSmartPointer<vtkPolyData> getPlane(vtkSmartPointer<vtkPoints> pPoints,
							vtkSmartPointer<vtkPoints> nPoints,int ref)
{
	double pPlane[3];
	double pNorm[3];

	pPoints->GetPoint(ref,pPlane);
	nPoints->GetPoint(ref,pNorm);

	std::cout << pPlane << std::endl;
	std::cout << pNorm<< std::endl;

	//Create Plane
	vtkSmartPointer<vtkPlaneSource> planeSource =
	vtkSmartPointer<vtkPlaneSource>::New();

	planeSource->SetCenter(pPlane[0],pPlane[1],pPlane[2]);
	planeSource->SetNormal(pNorm[0],pNorm[1],pNorm[2]);
	//	planeSource->SetPoint1(1,0,0);
	//	planeSource->SetPoint2(0,1,0);
	//	planeSource->SetXResolution(10);
	//	planeSource->SetYResolution(10);
	planeSource->Update();

	vtkSmartPointer<vtkPolyData>  pl = planeSource->GetOutput();
	return pl;
}

//Get a VTK Actor
vtkSmartPointer<vtkActor> getActorFromPoly(vtkSmartPointer<vtkPolyData> data)
{

	vtkSmartPointer<vtkPolyDataMapper> mapper =
	vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(data);

	vtkSmartPointer<vtkActor> actor =
	vtkSmartPointer<vtkActor>::New();

	actor->SetMapper(mapper);

	return actor;
}

