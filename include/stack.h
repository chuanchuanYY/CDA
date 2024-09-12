#ifndef __STACK__
#define __STACK__
#include <stdlib.h>
// 用链表实现

typedef int StackElementType;
typedef struct StackLinkNode
{
    StackElementType value;
    struct StackLinkNode* next;
    struct StackLinkNode* pre;
}StackLinkNode;

typedef struct Stack 
{
    StackLinkNode* head;
    StackLinkNode* tail;
    int count;
}Stack;

void initStack(Stack* stack);
int StackEnter(Stack* stack, StackElementType value);
int StackPop(Stack* stack,StackElementType* value);

#endif