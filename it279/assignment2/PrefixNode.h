/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description: Prefix Node header file.
*/
#ifndef _PREFIXNODE_H
#define _PREFIXNODE_H
#include "BunchOfWords.h"
#include <string>
#include <vector>
using namespace std;

class BunchOfWords;
class PrefixNode {

	public:
		PrefixNode(); // PrefixNode object constructor
		~PrefixNode(); // PrefixNode object destructor
		void add(string s, int counter);
		vector<string> search(string prefix, int counter);
		bool find(string word, int counter);

	private:
		BunchOfWords *alphabet;

};

#endif
