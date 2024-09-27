#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include "linkList.h"
#include "arrary.h"
#include "stack.h"
#include "queue.h"
#include "AVLTree.h"
void AVLTreeTest()
{
    AVLTree* tree;
    initAVLTree(&tree);
    printf("init AVLTree Count:%d\n",tree->count);
    AVLTreeInsert(tree,5);
    AVLTreeInsert(tree,1);
    AVLTreeInsert(tree,3);
    AVLTreeInsert(tree,-1);
    AVLTreeInsert(tree,7);
    printf("AVLTree Count:%d\n",tree->count);
    AVLTreeDump(tree);

    AVLTreeRemove(tree,4);
    AVLTreeRemove(tree,5);
    printf("AVLTree Count:%d\n",tree->count);
    AVLTreeDump(tree);
    AVLTreeDestory(tree);

}
void ArraryTest()
{
    Arrary arr;

    // init 
    initArray(&arr);

    // push some value  1,2,3
    push(&arr,1);
    push(&arr,2);
    push(&arr,3);
    
    dumpArrary(&arr);

    int resultSuccess = contain(&arr,2);
    int resultFailed  = contain(&arr,4);
    
    printf("success result:%d, failed result:%d\n",resultSuccess,resultFailed);

    // change value
    int* value; 
    arraryIndex(&arr,&value,1);
    *value = 200;
     
    dumpArrary(&arr);

}

void LinkListTest()
{
    LinkList list;

    initLinkList(&list);

    backPush(&list,1);
    backPush(&list,2);
    backPush(&list,3);
    backPush(&list,4);
    headInsert(&list,0);
    LinkNode* result = search(&list,5);
    if(result == NULL)
    {
        printf("result is null\n");
    }
    else 
    {
        printf("result :%d\n",result->value);
    }
    removeLinkListNode(&list,0);

    dump(&list);
}

void StackTest()
{
    Stack stack;
    initStack(&stack);

    // enter 1,2,3,4,5
    StackEnter(&stack,1);
    StackEnter(&stack,2);
    StackEnter(&stack,3);
    StackEnter(&stack,4);
    StackEnter(&stack,5);
    printf("stack count: %d\n",stack.count);

    // pop 5,4,3,2,1
    int pop1,pop2,pop3,pop4,pop5;
    StackPop(&stack,&pop1);
    StackPop(&stack,&pop2);
    StackPop(&stack,&pop3);
    StackPop(&stack,&pop4);
    StackPop(&stack,&pop5);
    printf("pop:%d,%d,%d,%d,%d \n",pop1,pop2,pop3,pop4,pop5);
    printf("count after pop %d",stack.count);
}


void QueueTest()
{
    Queue q;
    initQueue(&q);

    // enter some data ;
    queueEnter(&q,1);
    queueEnter(&q,2);
    queueEnter(&q,3);
    queueEnter(&q,4);

    printf("queue len: %d \n",q.len);

    // pop all data 
    int pop1,pop2,pop3,pop4;
    queuePop(&q,&pop1);
    queuePop(&q,&pop2);
    queuePop(&q,&pop3);
    queuePop(&q,&pop4);

    printf("%d,%d,%d,%d\n",pop1,pop2,pop3,pop4);
    printf("queue len after pop: %d \n",q.len);

}