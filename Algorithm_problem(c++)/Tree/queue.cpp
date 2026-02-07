#include"function.h"

void InitQueue(Queue &Q)
{
    Q.front = (LinkList)malloc(sizeof(Node));
    Q.rear = Q.front;
    Q.front->next = NULL;
    return;
}


void RearInsert(Queue &Q, ElemType e)
{
    LinkList qnew = (LinkList)malloc(sizeof(Node));
    qnew->data = e;
    qnew->next = NULL;
    Q.rear->next = qnew;
    Q.rear = qnew;
}

void FrontDelete(Queue &Q,ElemType &p)
{
    if (Q.front == Q.rear)
    {
        printf("队链为空\n");
        return;
    }
    LinkList qnew = Q.front->next;
    p=qnew->data;
    Q.front->next = qnew->next;
    if (Q.rear == qnew)
    {
        Q.rear = Q.front;
    }
    free(qnew);
}

bool Isempty(Queue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}
