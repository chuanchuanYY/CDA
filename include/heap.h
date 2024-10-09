#ifndef __HEAP__
#define __HEAP__
#include <stdlib.h>
typedef int ElementType;
#define INITSIZE  32
typedef struct Heap
{
    ElementType* data;
    int dataLenth;
    int index;
}Heap;

void initHeap(Heap* heap);
int heapPeek(Heap* heap,int* value);
int heapIsEmpty(Heap* heap);
int heapCount(Heap* heap,int* count);
int heapPop(Heap* heap,int* popValue);
int heapPush(Heap* heap,int value);
#endif