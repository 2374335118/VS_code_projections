#include<stdio.h>
#include<iostream>

#define MAXSIZE 5 

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE]={0};// 顺序队列的数组
    int front;                 // 队头指针
    int rear;                  // 队尾指针
} Queue;

bool EmptyQueue(Queue Q) // 判断队列空
{
  if(Q.rear==Q.front)
    {
      return true;
    }
    return false;
}

void Rearinsert(Queue &Q,ElemType e) // 元素e入队
{
    if((Q.rear+1)%MAXSIZE==Q.front) // 队满
    {
        printf("队满，无法入队\n");
        return;
    }
    Q.data[Q.rear]=e; 
    Q.rear=(Q.rear+1)%MAXSIZE; // 队尾指针后移
    printf("入队元素：%d\n",e);
    for(int i=0;i<MAXSIZE;i++)
    {
        printf("%d ",Q.data[i]);
    }
    printf("\n");
    return;
}

void FrontDelete(Queue &Q) // 队头元素出队
{
    if(Q.rear==Q.front) // 队空
    {
        printf("队空，无法出队\n");
        return;
    }
    ElemType e=Q.data[Q.front];
    Q.data[Q.front]=0;
    Q.front=(Q.front+1)%MAXSIZE;
    printf("出队元素为%d\n",e);
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", Q.data[i]);
    }
    printf("\n");
    return;

}

int main()
{
    Queue Q;
    Q.front = 0;
    Q.rear = 0;
    EmptyQueue(Q);
    Rearinsert(Q,10);
    Rearinsert(Q,20);
    Rearinsert(Q,30);
    Rearinsert(Q,40);
    Rearinsert(Q,50);
    FrontDelete(Q);
    FrontDelete(Q);
    FrontDelete(Q);
    FrontDelete(Q);
    FrontDelete(Q);
}