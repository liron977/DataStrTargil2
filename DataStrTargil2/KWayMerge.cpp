using namespace std;
#include "KWayMerge.h"
#include "MinHeap.h"
#include<stdio.h>
#include <iostream>
#include <cmath>
#include <fstream>

// A utility function to swap two elements
void KWayMerge::swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int KWayMerge::partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void KWayMerge::quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void KWayMerge::printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void KWayMerge::k_Way_Merge(int arr[], int k, int arr_size)
{
	if (arr_size <= k)
	{
		quickSort(arr, 0, arr_size - 1);
	/*	printArray(arr, arr_size);
		cout << "------------" << endl;*/
		return;
	}

	else
	{
		int index = 0, curr_index= 0;
		int upper_bound, lower_bounds;
		upper_bound = int(ceil(+(arr_size / double(k))));
		lower_bounds = int(floor((arr_size / double(k))));
		int div = arr_size % k;
		for (int i = 0; i < div; i++){
			index = index + upper_bound;
			k_Way_Merge(&arr[curr_index], k, upper_bound);
			curr_index = index;
		}
		for (int i = div; i < k; i++){
			index = index + lower_bounds;
			k_Way_Merge(&arr[curr_index], k, lower_bounds);
			curr_index= index;
		}
		int* tmp_arr = new int[arr_size];
		merge(arr, arr_size, k, tmp_arr);
		for (int i = 0; i < arr_size; i++) {
			arr[i] = tmp_arr[i];
		}
		delete[]tmp_arr;
	}
}
void KWayMerge::merge(int* arr, int arr_size, int k, int* saver_arr) {
	MinHeap heap(k);
	int div = arr_size % k;
	int upper_bound =int(ceil(+(arr_size / double(k))));
	int floorRound = int(floor((arr_size / double(k))));
	Indexs* index_arr = new Indexs[k];
	int t = 0,j=0, tmp_index =0;
	Pair* pair_arr = new Pair[k];
	for (int i = 0; i < div; i++) { // filling index array with a minimum of each (upper_bound size) sub-array
		index_arr[j].index = upper_bound * i;
		index_arr[j].size = upper_bound;
		j++;
	}
	for (int i = 0; i < k - div; i++) { //// filling index array with a minimum of each (floorRound size) sub-array
		index_arr[j].index = (floorRound * i + upper_bound * div);
		index_arr[j].size = floorRound;
		j++;
	}
	for (int i = 0; i < k; i++) {

		pair_arr[i].currIndex = index_arr[i].index;
		pair_arr[i].priority = arr[index_arr[i].index];
	}
	heap.buildHeap(pair_arr, k);
	for (int i = 0; i < arr_size; i++) {
		Pair p = heap.DeleteMin();
		saver_arr[t] = p.priority;
		int curr_index = p.currIndex;
		t++;
		tmp_index = findIndex(index_arr, curr_index, k); //return the num index in the origin arr 
		if (tmp_index != -1) {
			if (index_arr[tmp_index].size > 1) {
				index_arr[tmp_index].index++;
				index_arr[tmp_index].size--; // decreasing sub-array size 
				Pair pTmp = { arr[index_arr[tmp_index].index],index_arr[tmp_index].index };
				heap.Insert(pTmp);
			}
		}
	}

	delete[]index_arr;
	delete[]pair_arr;

}

int KWayMerge::findIndex(Indexs* index_arr, int value, int size)const
{
	for (int i = 0; i < size; i++) {

		if (index_arr[i].index == value)
			return i;
	}
	return -1;

}
//int KWayMerge::findFirstTaken(Indexs* index_arr, int size) {
//
//	for (int i = 0; i < size; i++) {
//
//		if (index_arr[i].size !=1)
//			return i;
//	}
//	return -1;
//
//}
void KWayMerge::printArrayToFile(int* arr, int arr_size, string outputFileName)
{
	ofstream myfile(outputFileName, ios::app);
	for (int i = 0; i < arr_size; i++) {
		if (i == arr_size - 1) {
			myfile << arr[i];
		}
		else{
			myfile << arr[i] << endl;
		}
	
	}
	myfile.close();
}