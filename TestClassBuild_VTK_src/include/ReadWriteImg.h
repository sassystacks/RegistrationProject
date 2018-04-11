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

#include "vtkPolyData.h"
#include "vtkSTLReader.h"
#include "vtkXMLPolyDataReader.h"
#include "string.h"
#include <iostream>

class ReadWriteImg
{
private:

//	vtkSmartPointer<vtkSTLReader> reader; //reader
	const char* fname; //filename for reader
	vtkSmartPointer<vtkPolyData> pdata;

public:
	ReadWriteImg(const char*); //constructor
	void setFname(const char* f){fname = f;}
	vtkSmartPointer<vtkPolyData> getPdata(){return pdata;}
	virtual ~ReadWriteImg();

};



#endif /* READWRITEIMG_H_ */
