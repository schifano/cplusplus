/*
	Name: Rachel A Schifano
	Course: IT 279
	Assignment 4: Which is the best sort of them all?
*/

#ifndef _SORTS_H_
#define _SORTS_H_

class Sorts
{
 public:
  static void insertion_sort(double *array, int length);
  static void quick_sort(double *array, int length);
  static void heap_sort(double *array, int length);
  static void merge_sort(double *array, int length);

 private:
  static void quick_sort(double *array, int left, int right);
  static int median3(double *array, int left, int right);
  static int partition(double *array, int left, int right, int pivot_index);
  static void merge(double *array, int s_left, int e_left, int s_right, int e_right);
};

#endif
