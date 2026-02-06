#include<stdio.h>
#include<iostream>

typedef char Elemtype;
typedef struct Tree
{
    Elemtype e;/* data */
    struct Tree* lchild;
    struct Tree* rchild;
}Tree,*tree;

typedef struct Tag
{
    tree t;//树的某个节点的地址值
    struct Tag* next;
}Tag,*tag;
