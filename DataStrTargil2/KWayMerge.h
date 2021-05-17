#ifndef _KWAYMERGE_H
#define  _KWAYMERGE_H

class KWayMerge
{
	void quickSort(int arr[], int low, int high);
	int partition(int arr[], int low, int high);
	void swap(int* a, int* b);

public:

	void k_Way_Merge(int arr[], int k, int arr_size);
	void printArray(int arr[], int size);
	void merge(int* arr1, int arr1_size, int arr2_size, int k);

};



#endif //_KWAYMERGE_H