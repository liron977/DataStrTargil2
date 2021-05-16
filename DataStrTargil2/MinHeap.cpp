#include "MinHeap.h"


minHeap::minHeap(int max)
{
    data = new Pair[max];
    maxSize = max;
    heapSize = 0;
    allocated = 1;
}

minHeap::~minHeap()
{
    if (allocated)
    {
        delete[] data;
    }
    data = nullptr ;
}
int minHeap::Parent(int node)
{
    return (node - 1) / 2;
}
int minHeap::Left(int node)
{
    return (2 * node + 1);
}
int minHeap::Right(int node)
{
    return (2 * node + 2);
}
Pair minHeap::DeleteMin()
{
    if (heapSize < 1)
    {

    }
    Pair min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    FixHeap(0);
    return min;
}
void minHeap::buildHeap(Pair A[], int n) {

    heapSize = maxSize = n;
    data = A;
    allocated = 0;

    for (int i = n / 2 - 1; i >= 0; i--) {
        FixHeap(i);
    }
}
void minHeap::FixHeap(int node)
{
    int min;
    int left = Left(node);
    int right = Right(node);

    if ((left < heapSize) && (data[left].priority < data[node].priority))
    {
        min = left;
    }
    else
    {
        min = node;
    }
    if ((right < heapSize) && (data[right].priority < data[min].priority))
    {
        min = right;
    }

    if (min != node)
    {
        Swap(&data[node], &data[min]);
            FixHeap(min);
    }
}
void minHeap :: Swap(Pair* a, Pair* b) {
       Pair t = *a;
        *a = *b;
        *b = t;
}
void minHeap::Insert(Pair item)
{
    if (heapSize == maxSize)
    {
        //
    }
    int i = heapSize;
    heapSize++;
    while ((i > 0) && (data[Parent(i)].priority < item.priority))
    {
        data[i] = data[Parent(i)];
        i = Parent(i);
    }
    data[i] = item;
}

