/*
 * ApplyRegistration.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: richard
 */

#include "ApplyRegistration.h"
//built class for optimizer


ApplyRegistration::ApplyRegistration(const char* fnameStaticMesh,
									const char* fnameDynamicMesh,
									const char* fnameOutputMesh)
{

	this->fnameStaticMesh = fnameStaticMesh;
	this->fnameDynamicMesh = fnameDynamicMesh;
	this->fnameOutputMesh = fnameOutputMesh;


}

int ApplyRegistration::writeSTL(){
	/*
	 *~~~~~~~~~~~~~~~~~~~~~~~~~ Import STL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 */
		//Set pixel type and dimension
		constexpr unsigned int Dimension = 3;
		typedef float PixelType;

		//instantiate reader for .stl type file
		itk::STLMeshIOFactory::RegisterOneFactory();
		using MeshType = itk::QuadEdgeMesh< PixelType, Dimension >;
		using ReaderType = itk::MeshFileReader< MeshType >;

		//Instantiate readers and writers
		ReaderType::Pointer reader1 = ReaderType::New();
		ReaderType::Pointer reader2 = ReaderType::New();

		//set reader for the static data set: terminal entry 1
		reader1->SetFileName(fnameStaticMesh);
		reader1->Update();

		//set reader for the moving data set: terminal entry 2
		reader2->SetFileName(fnameDynamicMesh);
		reader2->Update();

		//instantiate mesh from reader output
		MeshType::Pointer mesh1 = reader1->GetOutput();
		MeshType::Pointer mesh2 = reader2->GetOutput();

	/*
	 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 * ~~~~~~~~~~~~~~~~~~~~~ ITK Analysis ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 */

	//~~~~~~~~~~~~~~~~~~ Reduce Point Cloud for Mesh 2~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		//instantiate mesh to be filled with points from original mesh
		MeshType::Pointer meshRemovePoints = MeshType::New();

		MeshType::PointsContainerPointer points = mesh2->GetPoints( );
	    MeshType::PointsContainerConstIterator iterator = points->Begin();
	    MeshType::PointsContainerConstIterator itEnd = points->End();

	    unsigned int i = 0;
	    float maxVal = .905;
	    float minVal = .834;
		//copy original mesh with aneurysm removed
		while( iterator!= itEnd){

			MeshType::PointType p = iterator.Value();

			float zVal = p[2];




			if (zVal > maxVal || zVal <minVal ){
				meshRemovePoints->SetPoint(i++,p);
			}
			++iterator;
		}
		meshRemovePoints->Print(std::cout);


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Apply ICP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		using PointSetType = itk::QuadEdgeMesh< PixelType, Dimension >;
		using MetricType = itk::EuclideanDistancePointMetric< PointSetType, PointSetType >;

		MetricType::Pointer  metric = MetricType::New();

		// setup the tranform, optimizers, and registration.
		using TransformType = itk::Euler3DTransform< double >;

		TransformType::Pointer transform = TransformType::New();


		// Optimizer Type
		using OptimizerType = itk::LevenbergMarquardtOptimizer;

		OptimizerType::Pointer      optimizer     = OptimizerType::New();
		optimizer->SetUseCostFunctionGradient(false);

		// Registration Method
		using RegistrationType = itk::PointSetToPointSetRegistrationMethod<
																	PointSetType,
																	PointSetType >;

		//Instantiate the registration
		RegistrationType::Pointer   registration  = RegistrationType::New();

		// Scale the translation components of the Transform in the Optimizer

		OptimizerType::ScalesType scales( transform->GetNumberOfParameters() );

		constexpr double translationScale = 1000.0;   // dynamic range of translations
		constexpr double rotationScale = 1.0;   // dynamic range of rotations

		//set scales
		scales[0] = 1.0 / rotationScale;
		scales[1] = 1.0 / rotationScale;
		scales[2] = 1.0 / rotationScale;
		scales[3] = 1.0 / translationScale;
		scales[4] = 1.0 / translationScale;
		scales[5] = 1.0 / translationScale;

		// convergence criterion
		unsigned long   numberOfIterations =  1000; //possibly make dynamic variable
		double          gradientTolerance  =  1e-4;
		double          valueTolerance     =  1e-4;
		double          epsilonFunction    =  1e-5;


		optimizer->SetScales( scales );
		optimizer->SetNumberOfIterations( numberOfIterations );
		optimizer->SetValueTolerance( valueTolerance );
		optimizer->SetGradientTolerance( gradientTolerance );
		optimizer->SetEpsilonFunction( epsilonFunction );

		// Identity Transform
		transform->SetIdentity();

		registration->SetInitialTransformParameters( transform->GetParameters() );

		// Connect all the components required for the registration.
		registration->SetMetric(        metric        );
		registration->SetOptimizer(     optimizer     );
		registration->SetTransform(     transform     );
		registration->SetFixedPointSet( mesh1 );
		registration->SetMovingPointSet(   meshRemovePoints   );

		// Connect an observer
		// itk::CommandIterationUpdate commandIterator;

//		 itk::CommandIterationUpdate::Pointer observer = CommandIterationUpdate::New();
//		optimizer->AddObserver( itk::IterationEvent(), observer );

		int result = EXIT_SUCCESS;

		try
		{
		registration->Update();
		}
		catch( itk::ExceptionObject & e )
		{
		std::cerr << e << std::endl;
		return EXIT_FAILURE;
		}

		std::cout << "Solution = " << transform->GetParameters() << std::endl;
		std::cout << "Stopping condition: " << optimizer->GetStopConditionDescription() << std::endl;

	//~~~~~~~~~~~~~~~~~~~~~ Apply Registration to mesh ~~~~~~~~~~~~~~~~~~~~~~~~~~~

		using TransformMeshType = itk::TransformMeshFilter< MeshType, MeshType, TransformType >;
		TransformMeshType::Pointer meshTransform = TransformMeshType::New();

		meshTransform -> SetInput(mesh2);
		meshTransform -> SetTransform(transform);


	// ~~~~~~~~~~~~~~~~~~~~ Write Files ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		using WriterType = itk::MeshFileWriter< MeshType >;
		WriterType::Pointer writer = WriterType::New();

		writer->SetFileName(fnameOutputMesh);

		writer->SetFileTypeAsASCII();
		writer->SetInput( meshTransform->GetOutput() );
		writer->Update();

		return result;
}

ApplyRegistration::~ApplyRegistration() {
	// TODO Auto-generated destructor stub
}

