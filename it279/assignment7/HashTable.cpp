/*
	Rachel A Schifano
	IT 279
	Assignment 7
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Date.h"
#include "HashTable.h"
using namespace std;

// Constructor
HashTable::HashTable()
{
	primes();
}

// Destructor
HashTable::~HashTable()
{

}

// Read in the prime numbers
void HashTable::primes() {

	ifstream prime_file("primes-to-100k.txt");
	string line;
	int num;	

	// Check if file opened
	if (!prime_file.is_open()) {
		cout << "Error opening prime numbers file" << endl;
	} else {
		while(getline(prime_file, line)) {
			num = atoi(line.c_str());
			prime_numbers.push_back(num); // insert each number into prime vector
		}
	}
}

// Insert values into the hash table
void HashTable::insert(Date date_obj, string name)
{

}

// Method that returns all the names associated with a specific date
vector<string> HashTable::get_names(Date _date)
{
	
}


