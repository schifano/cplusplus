/*
	Name: Rachel A Schifano
	Professor: Dr. Shesh	
	Course: IT 279
	Description: Main file that runs the application.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "WordCompleter.h"
using namespace std;

int main() {
	
/*
	// reads in english.txt file line by line
	string line;
	WordCompleter wordComplete;
	ifstream file("english.txt"); // open file

	getline(file, line);
	while (!file.eof()) {

		string temp = "";
		// CORRECT LINE GETS OK
		
		// remove punctuation marks
		for (int i = 0; i < line.length(); i++) {

			cout << "line length " << line.length() << " " << line << endl;
			// LINE LENGTH IS COUNTING THE BREAK
	
			if (isalpha(line.at(i)) != 0) {
				// if char, add to array and lowercase
				temp += tolower(line.at(i));
			}	
		}
	
		wordComplete.add(temp); // THIS IS WHERE THE SEG FAULT OCCURS
		getline(file, line);


		/* THIS IS WHERE THE SEG FAULT OCCURS
		   I think that it is due to the add function? I tested it with only the add
		   outside of the find condition statement, and it can't seem to add to the dictionary.
		   I am thinking it ran out of memory. I tried several tests. It stops at abilities
		   each time it tries to add to the dictionary, which is about the 800th or so word. When
		   I tried a smaller dictionary of maybe 300 words, it would stop about half way through
		   which was still strange to me. On a local compiler it gave a Segmentation Fault 11, which
		   indicates out of memory. I tried to pass by reference, but it still got crazy. What is
		   crazier is that I was so sure this was all going to work well until this suddenly
		   happened, and perhaps it shouldn't have been called recursively.
		
		if (!wordComplete.find(temp)) {
			wordComplete.add(temp);
		}
	} 
*/

	// Test cases to at least get some of the program working
	WordCompleter wordComplete;
	wordComplete.add("meow"); 
	wordComplete.add("hi"); 
	wordComplete.add("high"); 
	wordComplete.add("dog"); 
	wordComplete.add("cookie");
	
	string inputWord;
	while (1) {
		// prompt user to enter a word
		cout << "Please enter a word: " << endl;
		getline(cin, inputWord);

		// test if input is blank
		if(inputWord.empty()) {
			return 0;
		}
		
		// lowercase word to make search case insensitive
		string temp;
		for (int j = 0; j < inputWord.length(); j++) {
			temp += tolower(inputWord.at(j));
		}

		// test if word is found
		bool find = wordComplete.find(temp);
		if (find) {
			// cout << "in find loop " << endl;
			cout << "The word " << temp << " was found." << endl;
		} else {
			// vector<string> temp = wordComplete.search(temp);
			// int size = temp.size();
			// cout << "The number of possible words are: " << size << endl;
		}
	}
	return 0;
}
