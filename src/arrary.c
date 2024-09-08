#include "arrary.h"
#include <stdlib.h>
#include <stdio.h>
// 1.增删改查功能

#define INIT_SIZE  100 // 默认初始化大小

void scale(Arrary* arr);
void initArray(Arrary* arr)
{
    arr->arr  = (int*)malloc(sizeof(int) * INIT_SIZE);
    arr->size = INIT_SIZE;
    arr->len  = 0;
}
void dumpArrary(Arrary* arr)
{
    int i = 0;
    for(i=0; i<arr->len; i++)
    {
        printf("%d  ",arr->arr[i]);
    }
    printf("\n");
}

// 如果Arrary包含该value 返回1 否则-1
int contain(Arrary* arr,int value)
{
    int i = 0 ;
    for(i=0; i<arr->len; i++)
    {
        if(arr->arr[i] == value)
        {
            return 1;
        }
    }
    return 0;
}

// 获取索引i 位置的值，并赋值给result
int arraryIndex(Arrary* arr,int** result ,int i)
{
    if(i < 0 || i >= arr->len)
    return -1;

    *result = &arr->arr[i];
    return 1;
}
// push a element to back
// return -1 if error
int push(Arrary* arr, int value)
{
    if(arr == NULL)
    return -1;

    if(arr->len >= arr->size)
    {
        scale(arr);
    }

    arr->arr[arr->len] = value;
    arr->len++;
}
// 扩容
void scale(Arrary* arr)
{
    int i = 0;
    int* newArr = (int*)malloc(arr->size * 2);
    // copy raw data to newArr
    for(i=0; i<arr->len; i++)
    {
        newArr[i] = arr->arr[i];
    }

    arr->arr = newArr;
    arr->size = arr->size * 2;
}

