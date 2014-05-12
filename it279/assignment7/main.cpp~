/*
	Rachel A Schifano
	IT 279
	Assignment 7
*/

#include "Date.h"
#include "HashTable.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int main (int argc, char *argv[])
{
	// Check to make sure user entered the correct number of arguments
	if (argc != 2) {
		cout << "Please enter the correct number of arguments\n" << endl;
	}

	// Create a HashTable for storing values
	HashTable hash_table;
	vector<string> names;

	// Instantiate variables for the data
	string day, month, year;
	int day_num, month_num, year_num;
	int i;

	// Open and read file
	ifstream input_file;
	input_file.open(argv[1]);
	//cout << argv[1] << endl; // TEST, OK
	
	// Test if file opened
	if (!input_file.is_open()) {
		// cout << "sad\n" << endl; // TEST
		cout << "The file could not be opened" << endl;
		return 0;
	} else {
		// cout << "YAY\n" << endl; // TEST
		string line, name;

		// Read in the given csv file
		while (getline(input_file, line)) {
			istringstream input_file(line);
			getline(input_file, name, ',');
			getline(input_file, month, '/');
			getline(input_file, day, '/');
			getline(input_file, year);
			
			// Convert each string value to an int
			day_num = atoi(day.c_str()); // c_str function converts
			month_num = atoi(month.c_str());
			year_num = atoi(year.c_str());

			// Create date object to store values
			Date date_obj(month_num, day_num, year_num);

			// Insert date object and name into hash table
			hash_table.insert(date_obj, name);
		}
	}

	// Read input from the user
	cout << "Please enter a date in the specified numerical format mm/dd/yyyy" << endl;
	string user_input;
	cin >> user_input;

	if (user_input.compare("0") == 0) {
		// cout << "Exit program" << endl; // TEST, OK
		return 0;
	} else {

		// Convert input into numerical valuess		
		// Date date();
		// hash_table.get_names(date);
	}
	return 0;
}
