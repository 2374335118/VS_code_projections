#include"function.h"

int main()
{
    tree pnew;//申请树的一个新节点
    tree root=NULL;//树根为空代表空树
    Elemtype c;
    tag queuenew=NULL,pfront=NULL,prear=NULL,pcur=NULL;
    while(scanf("%c",&c))
    {
        if(c=='\n')
        {
            break;//scanf读到换行符就结束
        }
        pnew=(tree)calloc(1,sizeof(Tree));//calloc申请树节点空间同时初始化NULL，空间大小为1*sizeof(Tree)
        pnew->e=c;
        queuenew = (tag)calloc(1, sizeof(Tag)); // calloc申请队列节点空间
        queuenew->t=pnew;
        if(root==NULL)
        {
            root=pnew;
            pfront=queuenew;
            prear=queuenew;
            pcur=queuenew;//队头、队尾、节点指针pcur都等于queuenew
        }
        else
        {
            //尾插入队
            prear->next=queuenew;
            prear=queuenew;
            //queuenew入树
            if(pcur->t->lchild==NULL)
            {
                pcur->t->lchild=pnew;
            }
            else if (pcur->t->rchild == NULL)
            {
                pcur->t->rchild=pnew;
                pcur=pcur->next;
            }
        }
    }
    return 0;
}