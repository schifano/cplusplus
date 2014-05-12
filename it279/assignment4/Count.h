/*
	Name: Rachel A Schifano
	Course: IT 279
	Assignment 4: Which is the best sort of them all?
	Description: Class that stores and maintains number of comparisons and assignments.
*/

#ifndef _COUNT_H_
#define _COUNT_H_

class Count
{
	public:
		// variablest to track all assignments
		double heap_assignments;
		double insert_assignments;
		double merge_assignments;
		double quick_assignments;
		
		// variables to track all comparisons
		double heap_comparisons;
		double insert_comparisons;			
		double merge_comparisons;
		double quick_comparisons;

		Count(); // Constructor
		~Count(); // Destructor
		
};

// Constructor
Count::Count()
{
	heap_assignments = 0;
	insert_assignments = 0;
	merge_assignments = 0;
	quick_assignments = 0;

	heap_comparisons = 0;
	insert_comparisons = 0;
	merge_comparisons = 0;
	quick_comparisons = 0;
}
// Destructor
Count::~Count()
{
}
#endif
