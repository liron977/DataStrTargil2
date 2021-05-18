#ifndef _INPUT_H
#define _INPUT_H
using namespace std; 
#include <string>
#include "KWayMerge.h"

class Input
{
	int* arr;
	int size_arr;
	int k;
	string inputFileName;
	string outputFileName;


public:
	void setUserInput();
	void setArrSize();
	void setK();
	bool isValidIndex(int _index) const;
	void setIndex(int _index);
	void setSize(int _size_arr);
	void setFilesName();
	void getInput();
	bool isValidNumber(int str_size, char* str) const;
	int getSize() const;
	void copyArr(int* dest_arr) const;
	int  getK() const;
	string getOutputFileName();
	void freeArray();
};


#endif
