/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description:
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
	
	/* TriangleModel triangle; // Create triangle model object.
	triangle.readInputFile(argv[1]); */

	std::string line; // read line by line
	std::vector<float> v; // v
	std::vector<int> f; // f

	std::ifstream objfile(argv[1]);

	while(!objfile.eof()) {
		std::getline(objfile,line);

		/* cout << line[0] << endl; // TESTESTTEST
		cout << line[1] << endl; // TESTESTTEST
		cout << line[2] <<  "last number" << endl; // TESTESTTEST
		*/

		if(line[0] == 'v') {
			line.erase(0,2); // remove the char and first space
	
			cout << line << " LINE " << endl;

			std::string delimeter = " ";
			size_t pos = 0;
			std::string token; // token

			while((pos = line.find(delimeter)) != std::string::npos) {
				
				// extract tokens
				token = line.substr(0,pos);
				
				std::cout << token << " token" << std::endl;
				
				// convert tokens into ints
				float num;
				num = atof(token.c_str());
				cout << num << " float" << endl;	

				// store int in vector
				v.push_back(num);

				
				cout << v[0] << " num in index " << 0 << endl;
				cout << v[1] << " num in index " << 1 << endl;
				cout << v[2] << " num in index " << 2 << endl;
				cout << v[3] << " num in index " << 3 << endl;
				cout << v[4] << " num in index " << 4 << endl;
				cout << v[5] << " num in index " << 5 << endl; 
								
				
	
				line.erase(0, pos+delimeter.length());
			}
			std::cout << line << std::endl;
		}
		else if (line[0] == 'f') {
					
			line.erase(0,2); // remove the char and first space
	
			// cout << line << " LINE " << endl; TEST TEST TEST

			std::string delimeter = " ";
			size_t pos = 0;
			std::string token; // token

			while((pos = line.find(delimeter)) != std::string::npos) {
				// extract tokens
				token = line.substr(0,pos);
				
				// std::cout << token << " token" << std::endl; TEST TEST TEST
				
				// convert tokens into ints
				int num;
				num = atoi(token.c_str());
				
//cout << num << " integer" << endl;	

				// store int in vector
				f.push_back(num);

				/* TEST TEST TEST
				cout << f[0] << " num in index " << 0 << endl;
				cout << f[1] << " num in index " << 1 << endl;
				cout << f[2] << " num in index " << 2 << endl;
				cout << f[3] << " num in index " << 3 << endl;
				cout << f[4] << " num in index " << 4 << endl;
				cout << f[5] << " num in index " << 5 << endl; */
								
				
	
				line.erase(0, pos+delimeter.length());
			}
			std::cout << line << std::endl;


			
			
		}
		if(!objfile.is_open()) {
			cout << "Unable to open file." << endl;
			return 0;
		}

	}
	objfile.close();


	// PRINT OUT VECTOR TEST TEST TEST TEST
	/* for(std::vector<string>::const_iterator i = v.begin(); i != v.end(); i++) {
		std::cout << *i << ' ' ;
	}*/

	return 0;
}



