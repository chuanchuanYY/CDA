#include "queue.h"
// 使用循环数组实现

void resize(Queue* queue);

/// @brief 初始化队列
/// @param queue 要初始化的队列
/// @return return -1 if success else -1
int initQueue(Queue* queue)
{
    if(queue == NULL)
    return -1;
    queue->arr = (ElementType*)malloc(sizeof(ElementType)*INIT_SIZE);
    queue->arrSize = INIT_SIZE;
    queue->head = 0;
    queue->tail = 0;
    queue->len = 0;

    return 1;
}

/// @brief 队列入队一个元素
/// @param queue 队列实例
/// @param value 要入队的值
/// @return reutrn 1 if success else -1
int queueEnter(Queue* queue,ElementType value)
{
    if(queue == NULL)
    return -1;

    if(queue->len >= queue->arrSize)
    {
        resize(queue);
    }

    *(queue->arr + (queue->tail % queue->arrSize)) = value;
    queue->tail++;
    queue->len++;

    return 1;
}

/// @brief 出队一个元素
/// @param queue 队列实例
/// @param value 存储出队元素的指针
/// @return return 1 if success ,-2 is empty else -1
int queuePop(Queue* queue, ElementType* value)
{
    if(queue == NULL)
    return -1;

    if(queue->len <=0)
    return -2;

    *value = *(queue->arr + (queue->head %queue->arrSize));
    queue->head++;
    queue->len--;

    return 1;
}
void resize(Queue* queue)
{
    int i = 0,j = 0;
    // 简单的2倍扩容数组
    ElementType* newArr = (ElementType*)malloc(sizeof(ElementType) * (queue->arrSize * 2));
    
    // copy elements
    
    if(queue->tail < queue->head)
    {
        for(i=queue->head; i<queue->arrSize; i++)
        {
            *(newArr+j) = *(queue->arr + i);
            j++;
        }
        for(i=0; i<queue->tail; i++)
        {
            *(newArr+j) = *(queue->arr + i);
            j++;
        }
    }
    else 
    {
        for(i=queue->head; i<queue->tail; i++)
        {
            *(newArr+j) = *(queue->arr + i);
            j++;
        }
    }
    
    ElementType* f = queue->arr;
    free(f);
    queue->arr = newArr;
    queue->head = 0;
    queue->tail = queue->len;
}

