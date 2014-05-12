
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	/* 
	   Function that reads provided OBJ file and returns true if successful, false otherwise.
	*/
	bool TriangleModel::readInputFile(char *filename) {

		string line; // read line by line
		ifstream objfile(filename);

		if(objfile.is_open()) {
			while(getline(objfile,line)) {
				cout << line << '\n';
			}
			objfile.close();
			return true;
		}
		else {
			cout << "Unable to open file.";
		}

		return false;
	}

	return 0;


}
