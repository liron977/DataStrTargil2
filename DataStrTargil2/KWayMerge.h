#ifndef _KWAYMERGE_H
#define  _KWAYMERGE_H
using namespace std;
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <math.h>

typedef struct {

	int index;
	int size; //size of the sub-array 

}Indexs;


class KWayMerge
{
	void quickSort(int arr[], int low, int high);
	int partition(int arr[], int low, int high);
	void swap(int* a, int* b);
	void merge(int* arr1, int arr1_size, int k, int* tmp_arr);
	int findIndex(Indexs* index_arr, int value, int size) const;

public:

	void k_Way_Merge(int arr[], int k, int arr_size);
	void printArray(int arr[], int size);
	//int findFirstTaken(Indexs* index_arr, int size);
	void printArrayToFile(int* arr, int arr_size, string outputFileName);

};



#endif //_KWAYMERGE_H