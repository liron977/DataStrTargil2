#ifndef _MINHEAP_H


typedef struct {

	int priority;
	int startIndex;
	int lastIndex;

}Pair;

class minHeap
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
	minHeap(int max);
	minHeap(int A[], int n);
	~minHeap();
	Pair Min();
	Pair DeleteMin();
	void Insert(Pair item);
	void buildHeap(Pair A[], int n);
	void Swap(Pair* a, Pair* b);

};
#endif
