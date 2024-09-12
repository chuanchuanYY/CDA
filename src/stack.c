#include <stack.h>
/// @brief 初始化一个栈
/// @param stack 指针指向要初始化的栈
void initStack(Stack* stack)
{
    stack->count = 0;
    stack->head  = NULL;
    stack->tail  = NULL;
}

/// @brief 入栈一个元素
/// @param stack 
/// @param value 
/// @return  return 1 if success else -1
int StackEnter(Stack* stack, StackElementType value)
{
    if(stack == NULL)
    {
        return -1;
    }

    StackLinkNode* newNode = (StackLinkNode*)malloc(sizeof(StackLinkNode));
    newNode->value = value;
    newNode->next = NULL;
    newNode->pre = NULL;

    if(newNode ==  NULL)
    {
        return -1;
    }
    if(stack->head == NULL)
    {
        stack->head = newNode;
        stack->tail = newNode;
    }
    else 
    {
        stack->tail->next = newNode;
        newNode->pre = stack->tail;
        stack->tail = newNode;
    }
    stack->count++;
    return 1;
}
/// @brief 出栈一个元素
/// @param stack 
/// @param value 用于存储出栈元素的指针
/// @return reutrn 1 if success else -1
int StackPop(Stack* stack,StackElementType* value)
{
    if(stack == NULL)
    {
        return -1;
    }

    if(stack->count <= 0)
    {
        return -1;
    }

    *value = stack->tail->value;
    if(stack->tail == stack->head)
    {
        free(stack->tail);
        stack->head = NULL;
        stack->tail = NULL;
    }
    else 
    {
        stack->tail = stack->tail->pre;
        free(stack->tail->next);
        stack->tail->next = NULL;
    }
    stack->count--;
    return 1;
}

