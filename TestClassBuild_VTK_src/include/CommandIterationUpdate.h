/*
 * CommandIterationUpdate.h
 *
 *  Created on: Apr 5, 2018
 *      Author: richard
 */

#ifndef SOURCE_DIRECTORY__COMMANDITERATIONUPDATE_H_
#define SOURCE_DIRECTORY__COMMANDITERATIONUPDATE_H_

#include "itkLevenbergMarquardtOptimizer.h"


namespace itk{

class CommandIterationUpdate: public itk::Command {

public:
	CommandIterationUpdate();
	virtual ~CommandIterationUpdate();

	using Self = CommandIterationUpdate;
	using Superclass = itk::Command;
	using Pointer = itk::SmartPointer<Self>;
	itkNewMacro( Self );

	using OptimizerType = itk::LevenbergMarquardtOptimizer;
	using OptimizerPointer = const OptimizerType *;

	void Execute(itk::Object *caller, const itk::EventObject & event) override
	{
	Execute( (const itk::Object *)caller, event);
	}

	void Execute(const itk::Object * object, const itk::EventObject & event) override
	{
	auto optimizer = dynamic_cast< OptimizerPointer >( object );
	if( optimizer == nullptr )
	  {
	  itkExceptionMacro( "Could not cast optimizer." );
	  }

	if( ! itk::IterationEvent().CheckEvent( &event ) )
	  {
	  return;
	  }
	}
};

} /* namespace itk */

#endif /* SOURCE_DIRECTORY__COMMANDITERATIONUPDATE_H_ */
