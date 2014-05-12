#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_

#include <vector>
#include <map>
#include <iostream>
using namespace std;

template<class T>
class PriorityQueue
{
  class HeapNode
  {
    friend class PriorityQueue;
  public:
    HeapNode();
    HeapNode(T obj,float priority,int *position);
    ~HeapNode();
  private:
    T obj;
    float priority;
    int *position;
  };

 public:
  PriorityQueue();
~PriorityQueue();
  void insert(T obj,float priority);
  T front();
  T pop();
  void changePriority(T obj,float new_priority);
  void remove(T obj);
  bool isEmpty();

 private:
  void percolateUp(int index);
  void percolateDown(int index);

 private:
  vector<HeapNode> heap;
  int numItems;
  map<T,int*> mapHeap;
};

template <class T>
PriorityQueue<T>::HeapNode::HeapNode()
{
  this->position = NULL;
}

template <class T>
PriorityQueue<T>::HeapNode::HeapNode(T obj,float priority,int *position)
{
  this->obj = obj;
  this->priority = priority;
  this->position = position;
}

template <class T>
PriorityQueue<T>::HeapNode::~HeapNode()
{
	}

template <class T>
PriorityQueue<T>::PriorityQueue()
{
  heap.push_back(HeapNode());
  numItems = 0;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	
  while (!isEmpty())
    pop();

}

template <class T>
void PriorityQueue<T>::insert(T obj,float priority)
{
  //create a new integer to store the index
  int *a = new int;
  *a = -1;
  //create a new HeapNode object
  HeapNode heapObj(obj,priority,a);
  
  //push it back onto the heap
  heap.push_back(heapObj);
  numItems++;
  //maintain its index
  *a = numItems;

  //add entry in map
  mapHeap[obj] = a;
  percolateUp(numItems);
}

template <class T>
T PriorityQueue<T>::front()
{
  if (numItems>=1)
    return heap[1]->obj;
}

template <class T>
T PriorityQueue<T>::pop()
{
  if (numItems>=1)
  {
    HeapNode obj = heap[1];

    //bring last item here
    heap[1] = heap[numItems];
    *(heap[1].position) = 1;

    numItems--;
    //remove entry from map
    mapHeap.erase(obj.obj);
    //clean up the memory of the integer pointer
    delete obj.position;

    if (numItems>0)
    	percolateDown(1);
    return obj.obj;
  }
}

template <class T>
void PriorityQueue<T>::changePriority(T obj,float new_priority)
{
  if (mapHeap.count(obj)==1)
  {
    int index = *(mapHeap[obj]);
    float old_priority = heap[index].priority;
    heap[index].priority = new_priority;

    if (old_priority>new_priority)
      percolateUp(index);
    else
      percolateDown(index);
  }
}

template <class T>
void PriorityQueue<T>::remove(T obj)
{
  changePriority(obj,heap[1].priority-1); //make it lowest priority so that it is at top of heap

  pop();
}

template <class T>
bool PriorityQueue<T>::isEmpty()
{
  return numItems<1;
}

template <class T>
void PriorityQueue<T>::percolateUp(int index)
{
  //remember that this is a min-heap

  int hole = index;
  HeapNode node = heap[hole];


  while ((hole>1) && (heap[hole/2].priority>node.priority))
  {
    heap[hole] = heap[hole/2];
    *(heap[hole].position) = hole;
    hole = hole/2;
  }
  heap[hole] = node;
  *(heap[hole].position) = hole;
}

template <class T>
void PriorityQueue<T>::percolateDown(int index)
{
  //remember that this is a min heap
  int child;
  int hole = index;
  HeapNode node = heap[hole];

  child = 2*hole;
  if (((child+1)<=numItems) && (heap[child+1].priority<heap[child].priority))
    child++;

  while ((hole<=numItems) && (child<=numItems) && (heap[child].priority<node.priority))
  {
    heap[hole] = heap[child];
    *(heap[hole].position) = hole;
    hole = child;
    child = 2*hole;
    if (((child+1)<=numItems) && (heap[child+1].priority<heap[child].priority))
      child++;
  }

  heap[hole] = node;
  *(heap[hole].position) = hole;
}
#endif
