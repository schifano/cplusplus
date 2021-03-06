/*
	Name: Rachel A Schifano
	Course: IT 279
	Assignment 4: Which is the best sort of them all?
*/

#include "Sorts.h"
#include "Count.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <time.h>
#include <cstring>
#include <cstdlib>

Count *count = new Count();

int main(int argc,char *argv[])
{ 
  if (argc!=3)
  { 
    cout <<"Please enter file name."<<endl;
    return -1;
  }
  double *array; 
  int length;
  int i,j;


  if (strcmp(argv[1],"-o")==0)
  {
      // this generates a random array of the length below and writes it to the provided file name
    length = 50000;
    array = new double[length];
    srand(time(NULL));
    for (i=0;i<length;i++)
      array[i] =(double) (-50 + rand()%100)/2.5;
    

    ofstream fout;
    fout.open(argv[2]);
    fout << length<<endl;
    for (i=0;i<length;i++)
      fout << array[i] << endl;
    
    fout.close();
  }

  if (strcmp(argv[1],"-i")==0)
  {
      //this runs the sorting algorithm on the input file
    fstream fin;
    fin.open(argv[2]);
    if (!fin.is_open())
    {
      cout <<"Could not open file"<<endl;
      return -1;
    }
    fin >>length;
    //create an array to hold the values from the file
    array = new double[length];    
    for (i=0;i<length;i++)
    {
      fin >> array[i];
    }
	/* SORTING ALGORITHMS */
	Sorts::insertion_sort(array,length); // INSERTION okay
	Sorts::quick_sort(array,length); // QUICK okay
	Sorts::merge_sort(array,length); // MERGE okay
	Sorts::heap_sort(array,length); // HEAP okay
    
//	cout << "Final sorted array: " << endl; // TEST
   
    for (i=0;i<length;i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
   }

	/* SORTING DATA */
	cout << "Elements sorted: " << length << endl;

	cout << endl;

	cout << "Assignments Heap: " << count->heap_assignments << endl;
	cout << "Assignments Insert: " << count->insert_assignments << endl;
	cout << "Assignments Merge: " << count->merge_assignments << endl;
	cout << "Assignments Quick: " << count->quick_assignments << endl;

	cout << endl;

	cout << "Comparisons Heap: " << count->heap_comparisons << endl;
	cout << "Comparisons Insert: " << count->insert_comparisons << endl;
	cout << "Comparisons Merge: " << count->merge_comparisons << endl;
	cout << "Comparisons Quick: " << count->quick_comparisons << endl;
  
  delete []array;
}
