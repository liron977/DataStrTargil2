#ifndef _INPUT_H
#define _INPUT_H
using namespace std;
#include <string>
#include "KWayMerge.h"

class Input
{
	int* arr;
	int size_arr=0;
	int k=0;
	string inputFileName;
	string outputFileName;

	void setArrSize();
	bool isValidIndex(int _index) const;
	void setIndex(int _index);
	void setSize(int _size_arr);
	void setFilesName();
	void getInput();
	bool isValidNumber(int str_size, char* str) const;
	void setK();
	bool wrongInput() const;

public:
	void setUserInput();
	int getSize() const;
	void copyArr(int* dest_arr) const;
	int getK() const;
	string getOutputFileName();
	void freeArray();

};


#endif