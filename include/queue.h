#ifndef __QUEUE__
#define __QUEUE__
#include <stdlib.h>
#define INIT_SIZE 35     // init size of arr 
typedef int ElementType;
typedef struct Queue
{
    ElementType* arr;
    int arrSize;

    int head;     // head index
    int tail;
    int len;     // lenth of queue element 
}Queue;

int initQueue(Queue* queue);
int queueEnter(Queue* queue,ElementType value);
int queuePop(Queue* queue, ElementType* value);
#endif 