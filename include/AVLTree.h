#ifndef __AVLTREE__
#define __AVLTREE__
#include <stdlib.h>
#include <stdio.h>
typedef int ElementType;

typedef struct AVLTreeNode
{
    ElementType value; // element 
    int height ; // height of node , -1 if node is null,0 is leaf node 
    struct AVLTreeNode *left ; // left child 
    struct AVLTreeNode *right; // right child   
}AVLTreeNode;

typedef struct AVLTree
{
    AVLTreeNode* root;
    int count; // count of element;
}AVLTree;

int AVLTreeNodeHeight(AVLTreeNode* node); 
void AVLTreeNodeUpdataHeight(AVLTreeNode *node);
int AVLTreeNodeBalanceFactor(AVLTreeNode* node);
AVLTreeNode* AVLTreeNodeRightRotate(AVLTreeNode* node);
AVLTreeNode* AVLTreeNodeLeftRotate(AVLTreeNode* node);


void initAVLTree(AVLTree** tree);
void AVLTreeDestory(AVLTree* tree);
void AVLTreeInsert(AVLTree* tree,ElementType value);
void AVLTreeRemove(AVLTree* tree,int value);
void AVLTreeDump(AVLTree* tree);
#endif