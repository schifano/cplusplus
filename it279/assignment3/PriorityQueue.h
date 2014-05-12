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

	// Node class that handles storing data and priority
	class Node {	

		public: 
			Node(T data, float priority); // constructor
			~Node(); // destructor

			// getters and setters to handle data
			T getData();
			float getPriority();
			void setPriority(float new_priority);

			T data;
			float priority;
	};

	public:
		PriorityQueue(); // constructor
		~PriorityQueue(); // deconstructor

		vector<Node> heap; // vector of node objects
		map<T, int> heap_map; // map that corresponds to heap

		// functions
		void insert(T obj, float priority);
		T front();
		T pop();
		bool isEmpty();
		void changePriority(T obj, float new_priority);
		void remove(T obj);

	private:
		void percolateUp(int index);
		void percolateDown(int index);
};

// Constructor
template <class T>
PriorityQueue<T>::PriorityQueue() {
}

// Deconstructor
template <class T>
PriorityQueue<T>::~PriorityQueue() {
}

// Inserts a new object with the given priority
template <class T> 
void PriorityQueue<T>::insert(T obj, float priority) {
	
	// create new node to store the data and priority
	Node node(obj, priority);
	// immediately add node to vector
	heap.push_back(node);
	percolateUp(heap.size());

/*
	cout << "HEAP AT 0 " << heap[0] << " " <<  endl;
	cout << "HEAP AT 1 " << heap[1] << " " <<  endl;
	cout << "HEAP AT 2 " << heap[2] << " " <<  endl;
	cout << "HEAP AT 3 " << heap[3] << " " <<  endl;
*/
	
}


// Returns but does not remove the object with the lowest priority (by number) currently in the queue
template <class T>
T PriorityQueue<T>::front() {
	// return first object
	T data = heap.at(0).getData();
	return data;
}

// Removes and returns the object with lowest priority (by number) currently in queue
template <class T>
T PriorityQueue<T>::pop() {

	// return first object
	T data = heap.at(0).getData();
	// percolateDown(0);
	return data;
}

// Returns true if the priority queue is empty, false otherwise
template <class T>
bool PriorityQueue<T>::isEmpty() {

	if (heap.size() == 0) {
		return true;
	}
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
void PriorityQueue<T>::percolateUp(int index) {

	int hole = index;
	Node data = heap[hole];

	// when hole becomes 1, stop
	while (hole > 0 && heap.at(hole / 2).getPriority() > data.getPriority()) {
		heap[hole] = heap[hole / 2];
		
		// store data and pointer int into map
		int *h_ptr;
		h_ptr = &hole;
		heap_map[heap[hole].getData()] = hole;

		hole = hole / 2;
	}
	heap[hole] = data;
}

// Percolate Down
template <class T>
void PriorityQueue<T>::percolateDown(int index) {

	int hole = index;
	Node data = heap[hole];
	int child = hole * 2;

	if((child+1) <= heap.size() & heap[child+1] < heap[child]) {
		child++;
	}

	while((child <= heap.size()) & (heap[child] < data)) {
		heap[hole] = heap[child];
		hole = child;
		child = 2 * hole;

		if(((child+1) <= heap.size()) & heap[child++] < heap[child]) {
			child++;
		}
		heap[hole] = data;
	}
}

// Node class functions
// Constructor
template <class T>
PriorityQueue<T>::Node::Node(T a_data, float a_priority) {

	// initialize data
	data = a_data;
	// initialize priority
	priority = a_priority;
}

// Deconstructor
template <class T>
PriorityQueue<T>::Node::~Node() {
}

// Getter for data
template <class T>
T PriorityQueue<T>::Node::getData() {
	return data;
}

// Getter for priority
template <class T>
float PriorityQueue<T>::Node::getPriority() {
	return priority;
}

// Setter for priority
template <class T>
void PriorityQueue<T>::Node::setPriority(float a_priority) {
	priority = a_priority;
}
#endif
