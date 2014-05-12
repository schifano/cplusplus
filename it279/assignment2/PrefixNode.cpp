/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description: Represents one node of this data structure.
*/
#include "PrefixNode.h"
#include "BunchOfWords.h"
using namespace std;

// Constructor
PrefixNode::PrefixNode() {
	// array of 26 objects (each representing a letter of the alphabet)
	alphabet = new BunchOfWords[26]; 
}

// Destructor
PrefixNode::~PrefixNode() {
	delete[] alphabet;
}

void PrefixNode::add(string s, int counter) {

	int index = s.at(counter) - 97; // normalize index
	alphabet[index].add(s, counter);

}

vector<string> PrefixNode::search(string prefix, int counter) {
	
	int index = prefix.at(counter) - 97; // normalize index
	return alphabet[index].search(prefix, counter);
}

bool PrefixNode::find(string word, int counter) {

	int index = word.at(counter) - 97; // normalize index
	return alphabet[index].find(word, counter);
}
