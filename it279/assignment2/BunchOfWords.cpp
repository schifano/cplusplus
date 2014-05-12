/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description: Class that creates objects with vectors and a PrefixNode pointer.
*/
#include "BunchOfWords.h"
#include "PrefixNode.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Constructor
BunchOfWords::BunchOfWords() {
	entries;
	PrefixNode* ptr_pn = NULL; // pointer to another PrefixNode object
}

// Destructor
BunchOfWords::~BunchOfWords() {
	// vectors are automatically destroyed
	if (ptr_pn != NULL) {
		delete ptr_pn;
		ptr_pn = NULL;
	}
}

void BunchOfWords::add(string s, int counter) {

	entries.push_back(s);
	// add word to the vector
	if (counter < s.length()-1 ) {

		// if the pointer is NULL and the end of the word has not been tested, create a new node
		if (ptr_pn == NULL) {
			ptr_pn = new PrefixNode();
		}
		ptr_pn->add(s,counter+1);
	}
}

vector<string> BunchOfWords::search(string prefix, int counter) {

	if (prefix.length()-1 == counter) {
		// cout << "IN SEARCH METHOD " << entries[0] << endl;
		// cout << entries[1] << endl;
		// cout << entries[2] << endl; seg faults bc nothing there
		return entries;
	}
	if (ptr_pn != NULL) {
		ptr_pn->search(prefix, counter+1);
		return entries;
	}
	vector<string> notFound;
	return notFound;
}

bool BunchOfWords::find(string word, int counter) {

	if (word.length()-1 == counter) {
		return true;
	}
	if (ptr_pn != NULL) {
		ptr_pn->find(word, counter+1);
	}
	return false;
}
