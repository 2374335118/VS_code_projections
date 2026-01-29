#include<stdio.h>
#include<stdlib.h>
#include<iostream>

typedef int ElemType;

typedef struct Node
{
    ElemType data;        // 节点数据域
    struct Node *next;    // 节点指针域
} Node, *LinkList;

typedef struct
{
    LinkList front;  // 队头指针
    LinkList rear; //队尾指针
}Linkqueue;

void InitQueue(Linkqueue &Q)
{
    Q.front=Q.rear=(LinkList)malloc(sizeof(Node));
    Q.front->next=NULL;
    return;
}

void PrintList(Linkqueue Q)
{
    Q.front = Q.front->next;
    while (Q.front!=NULL)
    {
        printf("%-3d", Q.front->data);
        Q.front = Q.front->next;
    }
    printf("\n");
}

void RearInsert(Linkqueue &Q,ElemType e)
{
    LinkList qnew=(LinkList)malloc(sizeof(Node));
    qnew->data=e;
    qnew->next=NULL;
    Q.rear->next=qnew;
    Q.rear=qnew;
    PrintList(Q);
}



void FrontDelete(Linkqueue &Q)
{
    if(Q.front==Q.rear)
    {
        printf("队链为空\n");
        return;
    }
    LinkList qnew=Q.front->next;
    Q.front->next=qnew->next;
    if(Q.rear==qnew)
    {
        Q.rear=Q.front;
    }
    free(qnew);
    PrintList(Q);
}

int main()
{
    Linkqueue Q;
    InitQueue(Q);
    RearInsert(Q, 10);
    printf("-----------------------\n");
    RearInsert(Q, 20);
    printf("-----------------------\n");
    RearInsert(Q, 30);
    printf("-----------------------\n");
    RearInsert(Q, 40);
    printf("-----------------------\n");
    FrontDelete(Q);
    printf("-----------------------\n");
    FrontDelete(Q);
    printf("-----------------------\n");
    FrontDelete(Q);
    printf("-----------------------\n");
    FrontDelete(Q);
    printf("-----------------------\n");
    FrontDelete(Q);
    printf("-----------------------\n");
}

