#ifndef __ARRARY__
#define __ARRARY__

typedef struct Arrary
{
    int *arr;
    int len; //当前元素数量
    int size;  // 数组的总容量 
}Arrary;
void initArray(Arrary* arr);
int push(Arrary* arr, int value);
int arraryIndex(Arrary* arr,int** result ,int i);
int contain(Arrary* arr,int value);
void dumpArrary(Arrary* arr);
#endif