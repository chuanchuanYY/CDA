#include "AVLTree.h"

AVLTreeNode* InsertHelper(AVLTreeNode* node,ElementType value);
AVLTreeNode*  RemoveHelper(AVLTreeNode* node, int value);
void DumpHelper(AVLTreeNode* node);
int Max(int left,int right)
{
    return left > right ? left : right;
}
void initAVLTreeNode(AVLTreeNode* *node)
{
    *node = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
    (*node)->height = 0 ;
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->value = 0;
}
/// @brief return height of node
/// @param node pointer of point to the instance  
/// @return return -1 if node is null else return height of node.
int AVLTreeNodeHeight(AVLTreeNode *node)
{
    return node == NULL? -1 : node->height;
}

/// @brief update node height 
/// @param node 
void AVLTreeNodeUpdataHeight(AVLTreeNode *node)
{
    // height of node equal to max subTree  + 1
 
    node->height = Max(AVLTreeNodeHeight(node->left),AVLTreeNodeHeight(node->right)) + 1;
}

int AVLTreeNodeBalanceFactor(AVLTreeNode* node)
{
    return AVLTreeNodeHeight(node->left) - AVLTreeNodeHeight(node->right);
}

/// @brief 失衡节点右旋
/// @return 
AVLTreeNode* AVLTreeNodeRightRotate(AVLTreeNode* node)
{
    AVLTreeNode* child = node->left;
    AVLTreeNode* grandChild = child->right;

    child->right = node;
    node->left = grandChild;

    AVLTreeNodeUpdataHeight(node);
    AVLTreeNodeUpdataHeight(child);
    return child;
}

/// @brief 左旋失衡节点
/// @param node 
/// @return 
AVLTreeNode* AVLTreeNodeLeftRotate(AVLTreeNode* node)
{
    AVLTreeNode* child = node->right;
    AVLTreeNode* grandChild = child->left;

    child->left = node;
    node->right = grandChild;

    AVLTreeNodeUpdataHeight(node);
    AVLTreeNodeUpdataHeight(child);

    return child;
}

AVLTreeNode* AVLTreeNodeRotate(AVLTreeNode *node)
{
    // get balance factor 
    int bf = AVLTreeNodeBalanceFactor(node);
    // 左偏
    if(bf > 1)
    {
        // 子节点还是左偏
        if(AVLTreeNodeBalanceFactor(node->left) >= 0)
        {   
            return AVLTreeNodeRightRotate(node);
        }
        else  
        {
            // 先对子节点左旋再右旋
            node->left = AVLTreeNodeLeftRotate(node->left);
            return AVLTreeNodeRightRotate(node);
        }
    }

    if(bf < -1) 
    {
        if(AVLTreeNodeBalanceFactor(node->right) <= 0)
        {
            return AVLTreeNodeLeftRotate(node);
        }
        else 
        {
            node->right = AVLTreeNodeRightRotate(node->right);
            return AVLTreeNodeLeftRotate(node);
        }
    }

    return node;
}

void AVLTreeInsert(AVLTree* tree,ElementType value)
{   
    if(tree == NULL)
    return;

    tree->root = InsertHelper(tree->root,value);
    tree->count++;
}
AVLTreeNode* InsertHelper(AVLTreeNode* node,ElementType value)
{
    if(node == NULL)
    {
       initAVLTreeNode(&node);
       node->value = value;
    }

    if(value > node->value)
    {
        node->right = InsertHelper(node->right,value);
    }
    else if(value < node->value)
    {
        node->left = InsertHelper(node->left,value);
    }
    else 
    {
        return node; // 重复节点不插入
    }

    AVLTreeNodeUpdataHeight(node);
    node = AVLTreeNodeRotate(node);
    return node;
}


void AVLTreeRemove(AVLTree* tree,int value)
{
    if(tree == NULL)
    return;

    tree->root = RemoveHelper(tree->root,value);
    tree->count--;
}

AVLTreeNode*  RemoveHelper(AVLTreeNode* node, int value)
{
    if(node == NULL)
    return NULL;

    if(value > node->value)
    {
        node->right = RemoveHelper(node->right,value);
    }
    else if(value < node->value)
    {
        node->left = RemoveHelper(node->left,value);
    }
    else 
    {
        if(node->left != NULL && node->right != NULL)
        {
            AVLTreeNode* temp = node->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            int tempValue = temp->value;
            node->right = RemoveHelper(temp,temp->value);
            node->value = tempValue;
        }
        else 
        {
            AVLTreeNode* child = node->left != NULL ? node->left : node->right;
            
            if(child == NULL)
            {
                free(node);
                return NULL;
            }
            free(node);
            node = child;
        }
    }
    // 
    AVLTreeNodeUpdataHeight(node);
    AVLTreeNodeRotate(node);
    return node;
}
void initAVLTree(AVLTree** tree)
{
    *tree = (AVLTree*)malloc(sizeof(AVLTree));
    (*tree)->count = 0;
    (*tree)->root = NULL;
}
void AVLTreeDestory(AVLTree* tree)
{
    free(tree);
}

void AVLTreeDump(AVLTree* tree)
{
    if(tree == NULL || tree->root == NULL)
    {
        return;
    }
    DumpHelper(tree->root);
    printf("\n");
}

void DumpHelper(AVLTreeNode* node)
{
    if(node == NULL)
    return;
    printf("%d ",node->value);

    DumpHelper(node->left);
    DumpHelper(node->right);
}