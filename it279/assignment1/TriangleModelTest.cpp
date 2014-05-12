/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description: File that tests and runs the TriangleModel.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
#include "TriangleModel.h"

int main(int argc, char* argv[]) {
	
	TriangleModel triangle; // Create triangle model object.
	triangle.readInputFile(argv[1]);
	cout << "Volume of filename " << argv[1] << " is: " << triangle.getVolume() << endl;

	return 0;
}



