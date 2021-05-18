#include "KWayMerge.h"
#include "MinHeap.h"
#include "Input.h"
#include <string>

void main() {

	Input i;
	KWayMerge k;
	i.setUserInput();
	int* arr = new  int[i.getSize()];
	i.copyArr(arr);
	k.k_Way_Merge(arr, i.getK(), i.getSize());
	k.printArrayToFile(arr, i.getSize(), i.getOutputFileName());
	k.printArray(arr, i.getSize());
	i.freeArray();
	delete[] arr;
}