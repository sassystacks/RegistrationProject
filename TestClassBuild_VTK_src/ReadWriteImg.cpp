/*
 * Circle.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: richard
 */

#include "ReadWriteImg.h"

ReadWriteImg::ReadWriteImg(const char* fname)

{
	this->fname = fname;
}
vtkSmartPointer<vtkSTLReader> ReadWriteImg::getReader()
// TODO Auto-generated constructor stub

{
	vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
	reader->SetFileName(fname);
	reader->Update();
	return reader;
}




