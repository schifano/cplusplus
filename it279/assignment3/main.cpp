/*
	Name: Rachel A Schifano
	Course: IT 279
	Assignment 3
	Description: A template class that implements a priority queue that uses a binary min-heap.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include "PriorityQueue.h"

using namespace std;

int main() {

	PriorityQueue<int> queue;
	queue.insert(33, 1.0);
	queue.front();
	queue.pop();

	

	return 0;
}
