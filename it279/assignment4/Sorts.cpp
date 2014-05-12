/*
	Name: Rachel A Schifano
	Course: IT 279
	Assignment 4: Which is the best sort of them all?
*/

#include "Sorts.h"
#include "Count.h"
#include <iostream>
using namespace std;

extern Count *count;
// Insertion Sort
void Sorts::insertion_sort(double *array, int length)
{
	for (int i = 1; i < length; i++) {
    		double tmp = array[i]; count->insert_assignments++; // ASSIGN
    		
		int j = i;
		while ((j >= 1) && (array[j-1] > tmp)) { count->insert_comparisons++; // COMPARE
		array[j] = array[j-1]; count->insert_assignments++; // ASSIGN
		j--;
	    }
	array[j]= tmp; count->insert_assignments++; // ASSIGN
  }
}

// Quicksort
void Sorts::quick_sort(double *array, int length)
{
//	cout << "inside quick sort \n" << endl; // TEST
	Sorts::quick_sort(array, 0, length-1);
}

// Quicksort - helper function
void Sorts::quick_sort(double *array, int left, int right)
{
//	cout << "inside helper quick sort \n" << endl; // TEST
	if (left < right) { count->quick_comparisons++; // COMPARE
		int pivot_index = Sorts::median3(array, left, right);
		pivot_index = Sorts::partition(array, left, right, pivot_index);
		Sorts::quick_sort(array, left, pivot_index-1);
		Sorts::quick_sort(array, pivot_index+1, right);
	}
	
}

// Quicksort - partition function
int Sorts::partition(double *array, int left, int right, int pivot_index)
{
//	cout << "inside partition\n" << endl; // TEST
	double pivot = array[pivot_index]; count->quick_assignments++; // ASSIGN
	swap(array[pivot_index], array[right]); count->quick_assignments++; // ASSIGN
	
	int i = left - 1;
	for (int j = left; j < right; j++) { count->quick_comparisons++; // COMPARE
		if (array[j] < pivot) { count->quick_comparisons++; // COMPARE
			i++;
			swap(array[i], array[j]); count->quick_assignments++; // ASSIGN
		}
	}
	swap(array[i+1], array[right]); count->quick_assignments++; // ASSIGN
	return i + 1;
}

// Quicksort -pivot function
int Sorts::median3(double *array, int left, int right)
{
//	cout << "inside median\n" << endl; // TEST
	int median = (left + right) / 2; 

	if (array[median] >= array[left]) {  count->quick_comparisons++; // COMPARE
		if(array[left] >= array[right]) {  count->quick_comparisons++; // COMPARE
			return left;
		} else { 
			return right;
		} 
	} else if (array[right] >= array[left]) { count->quick_comparisons++; // COMPARE
		if(array[left] >= array[median]) { count->quick_comparisons++; // COMPARE
			return left;
		} 
		else { 
			return median;
		} 
	} else if (array[left] >= array[right]) { count->quick_comparisons++; // COMPARE
		if (array[right] >= array[median]) { count->quick_comparisons++; // COMPARE
			return right;
		} 
		else { 
			return median;
		} 
	}
}

// Heapsort
void Sorts::heap_sort(double *array, int length)
{
	double heap[length];

	// Heapify the current array
	int index = -1, hole;
	for (int i = 0; i < length; i++) { 
		heap[i] = array[i]; count->heap_assignments++; // ASSIGN
		// percolateUp
		hole = index;
		double data = heap[hole]; 
		while(hole > 0 && heap[hole / 2] > data) { count->heap_comparisons++; // COMPARE
			heap[hole] = heap[hole / 2]; count->heap_assignments++; // ASSIGN
			hole = hole / 2; 
		} 
		heap[hole] = data; count->heap_assignments++; // ASSIGN
		index++;
	} 

	// sort into original array
	for(int i = 0; i < length; i++) { 
		double data = heap[0]; count->heap_assignments++; // ASSIGN
		heap[0] = heap[index--]; count->heap_assignments++; // ASSIGN

		// percolateDown
		int child, hole = 0;
		double sort_arr = heap[hole]; count->heap_assignments++; // ASSIGN
		while(hole * 2 <= index) { 
			child = hole * 2; 
			if (child != index && (heap[child+1] < heap[child])) { count->heap_comparisons++; // COMPARE
				child++;
			}
			if (heap[child] < sort_arr) { count->heap_comparisons++; // COMPARE
				heap[hole] = heap[child]; count->heap_assignments++; // ASSIGN
			} else {
				break;
			}
			hole = child;
		} 
		heap[hole] = sort_arr; count->heap_assignments++; // ASSIGN
		array[i] = data; count->heap_assignments++; // ASSIGN
	} 
}

// Merge Sort - non-recursive bottom up
void Sorts::merge_sort(double *array, int length)
{
//	cout << "inside merge sort\n" << endl; // TEST
	if (length < 2) {
		return;
	}
	int step_size = 1;
	int left, middle, right;
	while (step_size < length) {
		int i = 0;
		while (i < length) {
			left = i;
			if (i + step_size < length) {
				middle = i + step_size;
			} else { 
				middle = length;
			}
			if (i + 2 * step_size < length) {
				right = i + 2 * step_size;
			}
			else {
				right = length;
			}
			merge(array, left, middle, right, length);
			i = i + 2 * step_size;
		}
		step_size = 2 * step_size;
	}
}

// Merge 
void Sorts::merge(double* array, int left, int middle, int right, int length){
//	cout << "inside merge helper\n" << endl; // TEST
	double sort_arr[length];
 	int i = left;
   	int j = middle;
   	int k = left;
	// store the next smallest element
	while (i < middle && j < right) { count->merge_comparisons++; // COMPARE
        	if (array[i] < array[j]) { count->merge_comparisons++; // COMPARE
		    sort_arr[k] = array[i]; count->merge_assignments++; // ASSIGN
		    ++i;
		} else {
		    sort_arr[k] = array[j]; count->merge_assignments++; // ASSIGN
		    ++j;
		}
		++k;
	}
	// copy remaining elements from the first array
	while (i < middle) { count->merge_comparisons++; // COMPARE
		sort_arr[k] = array[i]; count->merge_assignments++; // ASSIGN
        	++i;
        	++k;
   	}
    	// copy remaining elements from the second array
	    	while (j < right) { count->merge_comparisons++; // COMPARE
		sort_arr[k] = array[j];  count->merge_assignments++; // ASSIGN
		++j;
		++k;
    	}
    	// Copy the merged array back to the original
    	for (int index = 0; index < right; ++index) { count->merge_comparisons++; // COMPARE
        	array[index] = sort_arr[index]; count->merge_assignments++; // ASSIGN
    	}
}

