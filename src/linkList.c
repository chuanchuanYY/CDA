#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

void initLinkList(LinkList *list)
{
    LinkNode* newNode;
    initLinkListNode(&newNode);
    list->count = 0;
    list->guard = newNode;
    list->tail  = list->guard;
}
void initLinkListNode(LinkNode* *node)
{
    *node = (LinkNode*)malloc(sizeof(LinkNode));
    (*node)->value = 0;
    (*node)->pre = NULL;
    (*node)->next = NULL;
}
// search node
// return null if not found
LinkNode* search(LinkList* list,int value)
{
    LinkNode* temp = list->guard->next;
    while(temp != NULL)
    {
        if(temp->value == value)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

// 移除一个元素
void removeLinkListNode(LinkList *list, int value)
{
    LinkNode* node = search(list,value);
    if(node == NULL)
    return;
    LinkNode* pre = node->pre;
    pre->next = pre->next->next;
    if(list->tail == node)
    {
        list->tail = pre;
    }
    free(node);
    list->count--;
}
// 头插，在头节点前插入一个元素
void headInsert(LinkList *list ,int value)
{
    LinkNode* newNode;
    initLinkListNode(&newNode);

    newNode->next = list->guard->next;
    list->guard->next->pre = newNode;
    newNode->pre = list->guard;
    list->guard->next = newNode; 

    list->count++;
}
// insert a node to tail of list;
void backPush(LinkList* list,int value)
{
    // 
    LinkNode* newNode ;
    initLinkListNode(&newNode);
    newNode->value = value;

    list->tail->next = newNode;
    newNode->pre = list->tail;
    list->tail = newNode;

    list->count++;
}

void dump(LinkList* list)
{
    LinkNode* temp = list->guard->next;
    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            printf("%d",temp->value);
        }
        else 
        {
            printf("%d ->",temp->value);
        }
        temp = temp->next;
    }
}