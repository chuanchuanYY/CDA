#include "heap.h"
#include <stdio.h>

void initHeap(Heap* heap)
{
    heap->data = (ElementType*)malloc(sizeof(ElementType)*INITSIZE);
    heap->dataLenth = INITSIZE;
    heap->index = 0;
}

int left(int index)
{
    return index*2 + 1;
}
int right(int index)
{
    return index*2 + 2;
}
int parent(int index)
{
    return (index -1) /2;
}

/// @brief 
/// @param value 
/// @return return 1 if success else faild 
int heapPeek(Heap* heap,int* value)
{
    if(value == NULL)
    return -1;

    *value = heap->data[0];
    return 1;
}
/// @brief 
/// @param heap 
/// @return return 1:ture 0:false ,else is error;
int heapIsEmpty(Heap* heap)
{
    if(heap == NULL)
    return -1;

    return heap->index == 0 ? 1 : 0;
}
int heapCount(Heap* heap,int* count)
{
    if(heap == NULL || count == NULL)
    return -1;

    *count = heap->index;
    return 1;
}

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void shiftUp(Heap* heap,int index)
{
    while(1)
    {
        int p = parent(index);
        if(p < 0 || heap->data[p] >= heap->data[index])
        {
            break;
        }
        swap(&heap->data[p],&heap->data[index]);
        index = p;
    }
}
int heapPush(Heap* heap,int value)
{
    if(heap == NULL)
    return -1;
    //
    if(heap->index >= heap->dataLenth)
    {
        ElementType* newData =
        (ElementType*)malloc(sizeof(ElementType)*heap->dataLenth*2);
        if(newData == NULL)
        return -2;
        heap->dataLenth = heap->dataLenth *2;
        int i = 0;
        for(;i<heap->index;i++)
        {
            newData[i] = heap->data[i];
        }
        free(heap->data);
        heap->data = newData;
    }
    
    heap->data[heap->index++] = value;
    shiftUp(heap,heap->index-1);
    return 1;
}

void shiftDown(Heap* heap, int index)
{
    while(1)
    {
        int l = left(index),r = right(index),max = index;
        if(l < heap->index && heap->data[l] > heap->data[max])
        {
            max = l;
        }

        if(r < heap->index && heap->data[r] > heap->data[max])
        {
            max = r;
        }

        if(max == index)
        {
            break;
        }

        swap(&heap->data[index],&heap->data[max]);
        index = max;
    }
}
int heapPop(Heap* heap,int* popValue)
{
   if(heap == NULL || popValue == NULL)
   return -1;

   if(heapIsEmpty(heap) == 1)
   return -2;

   *popValue = heap->data[0];
    heap->data[0] = heap->data[--heap->index];
    shiftDown(heap,0);
    return 1;
}