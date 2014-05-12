/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description: Word Completer keeps track of just one PrefixNode object, its root.
*/

#include "WordCompleter.h"
#include "PrefixNode.h"
#include <string>
using namespace std;

WordCompleter::WordCompleter() {
	// initializes word completer by making root equal to a blank PrefixNode object
	root;
}

WordCompleter::~WordCompleter() {
}

// Adds the given word 's' to the word completer, creating / filling in the nodes as necessary.
// Does not add word if present.
void WordCompleter::add(string s) {

	root.add(s,0);
}

// Searches for the prefix 'prefix' in the word completer
// returns a vector of strings corresponding to all words that start with 'prefix'
vector<string> WordCompleter::search(string prefix) {
	
	return root.search(prefix, 0);
}

// If found given word in word completer, return true, otherwise return false;
bool WordCompleter::find(string word) {
	
	return root.find(word, 0);
}


