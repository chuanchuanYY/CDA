#include <stdio.h>
#include "linkList.h"
// debug 或或者在VsCode 运行不了是 路径有中文
void main()
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