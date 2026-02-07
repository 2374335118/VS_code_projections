#include"function.h"

bool IsEmpty(Queue Q)
{
    return Q.front==Q.rear;
}

void InitQueue(Queue &Q)
{
    Q.front=Q.rear=(linklist)malloc(sizeof(LNode));
    Q.rear->next=NULL;
}

void Rearinsert(Queue &Q,Elemtype newtree)
{
    linklist qnew=(linklist)malloc(sizeof(LNode));
    qnew->e=newtree;
    qnew->next=NULL;
    Q.rear->next=qnew;
    Q.rear=qnew;
}

void Frontdelete(Queue &Q,Elemtype &detree)
{
    if(Q.front==Q.rear)
    {
        return;
    }
    linklist qdel=Q.front->next;
    Q.front->next=qdel->next;
    detree=qdel->e;
    if(Q.rear==qdel)
    {
        Q.rear=Q.front;
    }
    free(qdel);
}