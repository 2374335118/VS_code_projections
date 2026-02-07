#include<stdio.h>
#include<iostream>


typedef struct Tree//二叉树结构体
{
    char e;/* data */
    struct Tree* lchild;
    struct Tree* rchild;
}Tree,*tree;



typedef tree ElemType;

typedef struct Node
{
    ElemType data;     // 二叉树节点地址域
    struct Node *next; // 节点指针域
} Node, *LinkList;

typedef struct
{
    LinkList front; // 队头指针
    LinkList rear;  // 队尾指针
} Queue;

bool Isempty(Queue Q);
void FrontDelete(Queue &Q,ElemType &p);
void RearInsert(Queue &Q, ElemType e);
void InitQueue(Queue &Q);