/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description:

	1. Write a C++ class TriangleModel that represents one triangle model using two lists:
		a. A list of vertices
		b. A list of triangle indices
	2. This calss has exatly one constructor that takes no parameters, and a deconstructor.
	3. Write a function bool readInputFile(char *filename) in this class that reads the provided OBJ file 
	   and returns true if successful, false otherwise.
	4. Write a function float getVolume() in this class that computers and returns the volume of the triangle model.
*/

#ifndef _TRIANGLEMODEL_H
#define _TRIANGLEMODEL_H

class TriangleModel {

	public:
		TriangleModel();  // Constructor declared
		~TriangleModel(); // Destructor declared

	bool readInputFile(char *filename); // reads provided OBJ file and returns true if successful, false otherwise
	float getVolume(); // computes and returns the volume of the triangle model

	private:
		float volume; // variables
};

#endif
