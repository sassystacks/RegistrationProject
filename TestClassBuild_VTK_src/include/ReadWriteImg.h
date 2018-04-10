/*
 * ReadWriteImg.h
 *
 *  Created on: Mar 21, 2018
 *      Author: richard
 *
 *      This class if for loading image data through the vtk pipeline. As more filetypes are used
 *      I can simply add them to the constructor.
 */

#ifndef READWRITEIMG_H_
#define READWRITEIMG_H_

#include "vtkSTLReader.h"
#include <string>

class ReadWriteImg
{
private:

//	vtkSmartPointer<vtkSTLReader> reader; //reader
	const char* fname; //filename for reader

public:
	ReadWriteImg(const char*); //constructor
	void setFname(const char* f){fname = f;}
	vtkSmartPointer<vtkSTLReader> getReader();
};



#endif /* READWRITEIMG_H_ */
