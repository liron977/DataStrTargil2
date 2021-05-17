using namespace std;
#include "KWayMerge.h"
#include "MinHeap.h"
#include<stdio.h>
#include <iostream>
#include <cmath>


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
		printArray(arr, arr_size);
		cout << "------------" << endl;
		return;
	}
	else
	{
		int index = 0, tmp = 0, dummy_size = 0,tmp_tmp=0;
		double ceil3 = ceil(+(arr_size / double(k)));
		int div = arr_size % k;
		for (int i = 0; i < div; i++)
		{
			index = index + int(ceil3);
			k_Way_Merge(&arr[tmp], k, ceil3);
			tmp_tmp = tmp;
			tmp = index;
		}
		for (int i = div; i < k; i++)
		{
			double ceil3 = floor((arr_size / double(k)));
			index = index + ceil3;
			k_Way_Merge(&arr[tmp], k, ceil3);
			tmp_tmp = tmp;
			tmp = index;
		}
		int* tmp_arr = new int[arr_size];
		merge(arr, arr_size, k, tmp_arr);
		for (int i = 0; i < arr_size; i++) {
			arr[i] = tmp_arr[i];
		}
		delete []tmp_arr;
	}



}
void KWayMerge::merge(int* arr, int arr_size, int k,int* tmp_arr) {


	MinHeap heap(k);
	int div = arr_size % k;
	double topRound = ceil(+(arr_size / double(k)));
	double floorRound = floor((arr_size / double(k)));
	Indexs* index_arr = new Indexs[k];
	int t = 0;
	int j = 0;
	int tmpIndex = 0, nextIndex=0;
	Pair* tmp = new Pair[k];
	for (int i = 0; i < div; i++) {
		index_arr[j].index = topRound * i;
		index_arr[j].size = topRound;
		j++;
	}
	for (int i = 0; i < k-div; i++) {
		index_arr[j].index = floorRound * i+topRound*div;
		index_arr[j].size = floorRound;
		j++;
	}
	for (int i = 0; i < k; i++) {

		tmp[i].currIndex = index_arr[i].index;
		//tmp[i].lastIndex = index_arr[i + 1] - 1;
		tmp[i].priority = arr[index_arr[i].index];
		//tmp[i].startIndex = - 1;
	}
	heap.buildHeap(tmp,k);
	for (int i = 0; i < arr_size; i++) {
		Pair p = heap.DeleteMin();
		tmp_arr[t] = p.priority;
		int curr_index = p.currIndex;
		int nextIndex;
		t++;
		 tmpIndex = findIndex(index_arr, curr_index, k);
		 if (index_arr[tmpIndex].size <= 1) {

			/* nextIndex = findFirstTaken(index_arr, k);
			 if (nextIndex == -1) {
				 continue;
			 }
			 index_arr[nextIndex].index++;
			 index_arr[nextIndex].size--;
			 Pair pTmp = { arr[nextIndex],nextIndex };
			 heap.Insert(pTmp);*/
			 continue;
		 }
		 else
		 {
			 index_arr[tmpIndex].index++;
		/*	 if (index_arr[tmpIndex].size == 0)
			 {

			 }*/
			 index_arr[tmpIndex].size--;
			 Pair pTmp = { arr[index_arr[tmpIndex].index],index_arr[tmpIndex].index };
			 heap.Insert(pTmp);
		 }
	}

	delete []index_arr;
	delete[]tmp;

}

int KWayMerge::findIndex(Indexs* index_arr, int value,int size)
{
	for (int i = 0; i < size; i++) {

		if (index_arr[i].index == value)
			return i;
	}
}
int KWayMerge::findFirstTaken(Indexs* index_arr, int size) {

	for (int i = 0; i < size; i++) {

		if (index_arr[i].size !=1)
			return i;
	}
	return -1;

}





//void KWayMerge::merge(int* arr1, int arr1_size,int arr2_size ,int k)
//{
//	MinHeap heap(arr1_size+arr2_size);
//	Pair* tmp = new Pair[arr1_size + arr2_size];
//	int i = 0,j=0;
//	int curr_index1 = 0, curr_index2 = 0;
//	bool flag = false;
//	//while (i<arr1_size)
//	//{
//	//	tmp[i].currIndex = i;
//	//	tmp[i].lastIndex = arr1_size-1;
//	//	tmp[i].startIndex = 0;
//	//	tmp[i].priority = arr1[i];
//	//	i++;
//	//}
//	//while (j < arr2_size)
//	//{
//	//	tmp[i].currIndex = j;
//	//	tmp[i].lastIndex = arr2_size+ arr1_size;
//	//	tmp[i].startIndex = arr1_size;
//	//	tmp[i].priority = arr1[j+i];
//	//	i++;
//	//	j++;
//	//}
//	Pair p1 = { 0,arr1_size,arr1[0] };
//	Pair p2 = { 0,arr1_size+arr2_size,arr1[arr1_size] };
//	tmp[0] = p1;
//	tmp[1] = p2;
//	heap.buildHeap(tmp, arr1_size + arr2_size);
//	int t = 0;
//	for (int i = 0; i < arr1_size + arr2_size; i++) {
//
//		Pair p = heap.DeleteMin();
//		arr1[t] = p.priority;
//		t++;
//	
//		if (p.startIndex == 0) {
//
//			if (p.currIndex > curr_index1)
//				curr_index1 = p.currIndex;
//			if (p.currIndex == arr1_size)
//			{
//				flag = true;
//			}
//			else
//			{
//				heap.Insert(tmp[p.currIndex+1]);
//			}
//
//		}
//		if(flag|| p.startIndex==arr1_size)
//		{
//			if (flag) {
//				heap.Insert(tmp[arr1_size + curr_index2 + 1]);
//				continue;
//			}
//			else
//			{
//				if (p.currIndex > curr_index2)
//					curr_index2 = p.currIndex;
//			}
//			if (p.currIndex == arr1_size+arr2_size)
//			{
//				break;
//			}
//			heap.Insert(tmp[arr1_size + p.currIndex+1]);
//		}
//
//	}
//
//}
