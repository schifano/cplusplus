/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description: Word Completer header file.
*/
#ifndef _WORDCOMPLETER_H
#define _WORDCOMPLETER_H
#include "PrefixNode.h"
#include <vector>
#include <string>
using namespace std;

class WordCompleter {

	public:
		WordCompleter(); // Constructor
		~WordCompleter(); // Destructor
		void add(string s); // adds the given word 's' to the word completer
		vector<string> search(string prefix); // searches for the prefix in word completer
		bool find(string word); // if found given word in word completer, returns true otherwise false

	private:
		PrefixNode root;
};
#endif
