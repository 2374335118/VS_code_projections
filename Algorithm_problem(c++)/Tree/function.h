#include<iostream>

typedef struct Tree
{
    char c;
    struct  Tree* lchild;
    struct  Tree* rchild;
}Tree,*tree;

typedef tree Elemtype;
typedef struct LNode
{
    Elemtype e;
    struct LNode* next;
}LNode,*linklist;

typedef struct Queue
{
    linklist front;
    linklist rear;
}Queue;

bool IsEmpty(Queue Q);
void InitQueue(Queue &Q);
void Rearinsert(Queue &Q, Elemtype newtree);
void Frontdelete(Queue &Q, Elemtype &detree);

void Treebuild(tree &t, Queue &Q);
void PreOrder(tree t);
void InOrder(tree t);
void PostOrder(tree t);
void LevelOrder(tree t);