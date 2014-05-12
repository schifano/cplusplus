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
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "TriangleModel.h"

	vector<float> v; // positions of the vertices
	vector<int> f; // indices of the vertex

	// Constructor defined
	TriangleModel::TriangleModel() {
	}
	// Destructor defined
	TriangleModel::~TriangleModel() {
	}

	/* 
	   Function that reads provided OBJ file and returns true if successful, false otherwise.
	*/
	bool TriangleModel::readInputFile(char *filename) {
		string line; // read line by line
		ifstream objfile(filename);

		while(!objfile.eof()) {
			getline(objfile,line);

			// tests for 'v' or 'f' char
			// tokenizes lines to extract numerical values for each vector
			if(line[0] == 'v') {
				line.erase(0,2); // remove the char, keep first space
				string delimeter = " ";

				size_t pos = 0;
				string token; // token
				
				while((pos = line.find(delimeter)) != string::npos) {
					// extract tokens
					token = line.substr(0,pos);

					// convert tokens into ints
					float num;
					num = atof(token.c_str());	

					// store int in vector
					v.push_back(num);
					line.erase(0, pos+delimeter.length());
						
					if ((pos = line.find(delimeter)) == string::npos) {
						// convert tokens into ints
						token = line.substr(0,line.length()-1);
						float num;
						num = atof(token.c_str());	

						// store int in vector
						v.push_back(num);
						line.erase(0,line.length());
					}
				}
			}
			else if (line[0] == 'f') {	
				line.erase(0,2); // remove the char and first space

				string delimeter = " ";
				size_t pos = 0;
				string token; // token

				while((pos = line.find(delimeter)) != string::npos) {
					// extract tokens
					token = line.substr(0,pos);
				
					// convert tokens into ints
					int num;
					num = atoi(token.c_str());

					// store int in vector
					f.push_back(num);
					line.erase(0, pos+delimeter.length());
				}
			}
			if(!objfile.is_open()) {
				cout << "Unable to open file." << endl;
				return false;
			}
		}
		objfile.close();
		return true;
	}

	/*
	   Function that computes and returns the volume of the triangle model.
	*/
	float TriangleModel::getVolume() {
		float volume = 0.0;
		float subtotal = 0.0;
		float x1, x2, x3, y1, y2, y3, z1, z2, z3;
		int valueF;
		int startPos;
		
		int counter = 1;
		int i;
		for(i = 0; i < f.size(); i++) {
			valueF = f[i]; // retrieve value from f
			startPos = (valueF * 3) - 3; // calculate starting position for vertices

			// keep counter for each line of indices of the vertex
			switch(counter) {
			case 1: 
				x1 = v[startPos];
				y1 = v[startPos+1];
				z1 = v[startPos+2];
				counter++;
				break;	
			case 2:
				x2 = v[startPos];
				y2 = v[startPos+1];
				z2 = v[startPos+2];
				counter++;
				break;	
			case 3:
				x3 = v[startPos];
				y3 = v[startPos+1];
				z3 = v[startPos+2];
				counter++;
				break;
			default:
				break;
			}
			if (counter == 4) {
				/* I got stumped / stuck at this part. I could not figure out
				   why weird values were being calculated and nothing was going into
				   my subtotal or volume. I speculated it was garbage? I am not sure
				   how to handle this, but at least I didn't give up. */
				subtotal = x1*(y2*z3-y3*z2)-y1*(x2*z3-x3*z2)+z1*(x2*y3-x3*y2) / 6;
				volume = volume + subtotal;	
				counter = 1; // reset counter	
			}
		}
		return volume;
	}

