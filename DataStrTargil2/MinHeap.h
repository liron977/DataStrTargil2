#ifndef _MINHEAP_H
#define _MINHEAP_H

typedef struct {

	int priority;
	int currIndex;

}Pair;

class MinHeap
{

private:
	Pair* data;
	int maxSize;
	int heapSize;
	int allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public:
	MinHeap(int max);
	~MinHeap();
	Pair Min();
	Pair DeleteMin();
	void Insert(Pair item);
	void Swap(Pair& a, Pair& b);
	void buildHeap(Pair A[], int n);

};
#endif //_MINHEAP_H