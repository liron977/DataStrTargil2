#include "KWayMerge.h"
#include "MinHeap.h"


void main() {

	KWayMerge k;


		int arr[] = { 10, 7, 8, 9, 1, 5 };
		//int arr[] = { 1,5,2,0,5,2,3,4224,335,2141,45,3,66,225,445,66,33 };

		//int arr[] = { 1,5,2,0,5,2,55,44 };
		int size = 6;
		k.k_Way_Merge(arr, 2, size);
		k.printArray(arr, size);
}