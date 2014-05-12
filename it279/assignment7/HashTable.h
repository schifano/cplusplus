/*
	Rachel A Schifano
	IT 279
	Assignment 7
*/

#include "Date.h"
#include <string>
#include <vector>
using namespace std;

class HashTable {

	// Node class that contains all hash values
	class Node {
		friend class HashTable;

		public:
			// constructor
			Node() {
				date_node = NULL;
				isNULL = true;
			}

			// destructor
			~Node() {
			}			


		private:
			Date *date_node;			
			bool isNULL;
			vector<string> hash_names;
	};

	public:
		HashTable();
		~HashTable();
		vector<string> get_names(Date _date);
		void insert(Date date_obj, string name); // accessible by main

	private:
		void primes(); // read in the prime numbers
		vector<int> prime_numbers; // vector to store prime values

};
