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
	void quickSort(int arr[], int low, int high) const;
	int partitionV1(int arr[], int left, int right) const;
	void swap(int* a, int* b) const;
	void merge(int* arr1, int arr1_size, int k, int* tmp_arr) const;
	int findIndex(Indexs* index_arr, int value, int size) const;

public:

	void k_Way_Merge(int arr[], int k, int arr_size);
	void printArray(int arr[], int size) const;
	void printArrayToFile(int* arr, int arr_size, string outputFileName)const;

};



#endif //_KWAYMERGE_H