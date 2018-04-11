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

	int fname_length = strlen(fname);
	if(fname_length >= 4 && strcmp(fname+(fname_length-4),".stl")==0){
		vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
			reader->SetFileName(fname);
			reader->Update();
			pdata = reader->GetOutput();

		std::cout << "The filename is : " << fname << std::endl;
	}
	else if(fname_length >= 4 && strcmp(fname+(fname_length-4),".vtp")==0){
		vtkSmartPointer<vtkXMLPolyDataReader> reader = vtkSmartPointer<vtkXMLPolyDataReader>::New();
			reader->SetFileName(fname);
			reader->Update();
			pdata = reader->GetOutput();
	}

	else{
		std::cout << "File Could not be read." << std::endl;
	}
}
ReadWriteImg::~ReadWriteImg(){

}





