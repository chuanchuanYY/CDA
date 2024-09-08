#ifndef __LINKLIST__
#define __LINKLIST__

typedef struct LinkNode
{
    int value;
    struct LinkNode* pre;
    struct LinkNode* next;
}LinkNode;

typedef struct LinkList
{
    LinkNode* guard; // 哨兵头节点
    LinkNode* tail;
    int count;
}LinkList;



void initLinkList(LinkList* list);
void destroy(LinkList * list);
LinkNode* search(LinkList* list,int value);
void headInsert(LinkList *list ,int value);
void backPush(LinkList* list,int value);
void dump(LinkList* list);
void initLinkListNode(LinkNode* *node);
void removeLinkListNode(LinkList *list, int value);
#endif