//
//  main.cpp
//  BinarySearchTree_C++
//
//  Created by chenyufeng on 9/26/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct BTNode{
    int data;
    struct BTNode *lChild;
    struct BTNode *rChild;
}BiTNode;

//声明
void CreateBinarySearchTree(BiTNode **T);
void Insert(BiTNode **T,int x);
void MiddleOrder(BiTNode *T);
void PreOrder(BiTNode *T);

//创建二叉查找树
/**
 *  输入-1时创建结束,其实是一个不断插入的过程
 */
void CreateBinarySearchTree(BiTNode **T)
{
    cout << "请输入创建二叉查找树的数字序列：" << endl;

    int num;
    cin >> num;

    while (num != -1)
    {
        Insert(T,num);
        cin >> num;
    }

    cout << "二叉查找树创建成功" << endl;
    return;
}

//插入节点
void Insert(BiTNode **T,int x)
{
    //这里创建一个要插入的节点
    BiTNode *pInsert = new BiTNode;
    pInsert->data = x;
    pInsert->lChild = NULL;
    pInsert->rChild = NULL;

    if ((*T) == NULL)
    {
        *T = pInsert;
        return;
    }

    // 当前节点的左子树为空，并且值小于根节点值
    if ((*T)->lChild == NULL && x < (*T)->data)
    {
        (*T)->lChild = pInsert;
        return;
    }

    if ((*T)->rChild == NULL && x > (*T)->data)
    {
        (*T)->rChild = pInsert;
        return;
    }

    // 递归实现
    // 没有找到合适的节点，继续在左子树查找
    if (x < (*T)->data)
    {
        Insert(&(*T)->lChild, x);
    }

    if (x > (*T)->data)
    {
        Insert(&(*T)->rChild, x);
    }

    return;
}

//中序遍历二叉查找树
//打印的应该是一个递增的序列
void MiddleOrder(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        MiddleOrder(T->lChild);
        cout << T->data << " ";
        MiddleOrder(T->rChild);
    }
}

//先序遍历二叉查找树
//因为先序遍历+中序遍历 可以唯一确定一棵树，等下可以验证树是否正确
void PreOrder(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        cout << T->data << " ";
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}

//查找某一个值
//返回1表示找到该值，返回0表示没有找到
void SearchValue(BiTNode *T,int x)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        if (x < T->data)
        {
            //查左子树
            SearchValue(T->lChild, x);
        }
        else if (x > T->data)
        {
            //查右子树
            SearchValue(T->rChild, x);
        }
        else
        {
            //找到该值
            cout << "该值的内存地址为：" << T << endl;
            return;
        }
    }

    return;
}

int main(int argc, const char * argv[])
{
    BiTNode *tree;

    //这个是引用传递
    CreateBinarySearchTree(&tree);

    MiddleOrder(tree);
    cout << endl;

    cout << "请输入要查找的元素：";
    int searchValue;
    cin >> searchValue;
    SearchValue(tree,searchValue);

    cout << "先序遍历：";
    PreOrder(tree);
    cout << "中序遍历：";
    MiddleOrder(tree);//遍历检查
    cout << endl;
    
    return 0;
}
