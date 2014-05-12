/*
	Name: Rachel A Schifano
	Course: IT 279
	Assignment 3
*/
#ifndef _PRIORITYQUEUE_
#define _PRIORITYQUEUE_

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

template <class T> // make generic data type
class PriorityQueue {

	public:
		PriorityQueue();
		~PriorityQueue(); // deconstructor

		int hole;
		vector<float> heap; // vector of objects

		map<int, T> Priorities;

		void insert(T obj, float priority);
		T front();
		T pop();
		bool isEmpty();
		void changePriority(T obj, float new_priority);
		void remove(T obj);


		int counter;
	private:
		int percolateUp(int index);
		void percolateDown(int index);
};

// Constructor
template <class T>
PriorityQueue<T>::PriorityQueue() {

	heap.push_back(-1.0); // reserve the first spot of the array
	counter = 0;
}

// Deconstructor
template <class T>
PriorityQueue<T>::~PriorityQueue() {
}

// Inserts a new object with the given priority
template <class T> 
void PriorityQueue<T>::insert(T obj, float priority) {

	/* Add element to bottom level of the heap.
	   Compare added element to parent.
	   If not correct order, swap. */

	heap.push_back(priority);
	int index = percolateUp(heap.size());
	int *index_ptr = &index;
	Priorities[obj] = *index_ptr;

	counter++; 
	cout << "HEAP AT 0 " << heap[0] << " " << counter << endl;
	cout << "HEAP AT 1 " << heap[1] << " " << counter << endl;
	cout << "HEAP AT 2 " << heap[2] << " " << counter << endl;
	cout << "HEAP AT 3 " << heap[3] << " " << counter << endl;
	
}


// Returns but does not remove the object with the lowest priority (by number) currently in the queue
template <class T>
T PriorityQueue<T>::front() {

	typename map<int, T>::iterator it;
	for (it = Priorities.begin(); it != Priorities.end(); it++) {
		if (it->second == 1) { // if matches value which is priority
			return it->first; // key
		}
	}
}

// Removes and returns the object with lowest priority (by number) currently in queue
template <class T>
T PriorityQueue<T>::pop() {

	T obj;
	typename map<int, T>::iterator it;
	for (it = Priorities.begin(); it != Priorities.end(); it++) {
		if (it->second == 1) { // if matches value which is priority
			obj = it->first; // key
		}
	}
	
	cout << "HEAP AT 0 " << heap[0] << endl;
	cout << "HEAP AT 1 " << heap[1] << endl;
	cout << "HEAP AT 2 " << heap[2] << endl;
	// heap.erase(heap.begin()+1,heap.begin()+2);
	cout << "HEAP AT 0 " << heap[0] << endl;
	cout << "HEAP AT 1 " << heap[1] << endl;
	cout << "HEAP AT 2 " << heap[2] << endl;
	
	percolateDown(1);
	return obj;

}

// Returns true if the priority queue is empty, false otherwise
template <class T>
bool PriorityQueue<T>::isEmpty() {

	if (heap.size() == 1) {
		cout << "TRUE\n" << endl; // TEST
		return true;
	}
	cout << "FALSE\n" << endl; // TEST
	return false;
}

// Changes the priority of an existing object to the new priority
// This function does not do anything if the provided object does not exist in the priority queue.
template <class T>
void PriorityQueue<T>::changePriority(T obj, float new_priority) {

}

// Removes a particular object from the priority queue.
// First changes priority to be the greatest in the queue and then pops it off.
template <class T>
void PriorityQueue<T>::remove(T obj) {



}

// Percolate Up
template <class T>
int PriorityQueue<T>::percolateUp(int index) {

	hole = index;
	T data = heap[hole];

	// when hole becomes 1, stop
	while (hole > 2 && heap[hole / 2] > data) {
		heap[hole] = heap[hole / 2];
		hole = hole / 2;
	}
	heap[hole] = data;
	return hole;
}

// Percolate Down
template <class T>
void PriorityQueue<T>::percolateDown(int index) {

	hole = index;
	T data = heap[hole];

	// when hole becomes 1, stop
	while (hole > 1 && heap[hole / 2] < data) {
		heap[hole] = heap[hole / 2];
		hole = hole / 2;
	}
	heap[hole] = data;
}

#endif
