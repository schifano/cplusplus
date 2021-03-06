/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description: BunchOfWords header file.
*/
#ifndef _BUNCHOFWORDS_H
#define _BUNCHOFWORDS_H
#include "PrefixNode.h"
#include <vector>
#include <string>
using namespace std;

class PrefixNode;
class BunchOfWords {

	public:
		BunchOfWords(); // BunchOfWords object constructor
		~BunchOfWords(); // BunchOfWords object destructor
		void add(string s, int counter); // adds a string to the vector
		vector<string> search(string prefix, int counter);
		bool find(string word, int counter);
	
	private:
		vector<string> entries; // vector stores bunch of words
		PrefixNode * ptr_pn; // pointer to another PrefixNode object
};
#endif
