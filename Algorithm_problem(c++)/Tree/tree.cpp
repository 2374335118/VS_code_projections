#include"function.h"
//abcdefghij
void Treebuild(tree &t,Queue &Q)
{
    tree root=NULL;
    linklist pcur;
    InitQueue(Q);
    pcur=Q.front;
    char c;
    while(scanf("%c",&c))
    {
        if(c=='\n')
        {
            break;
        }
        t = (tree)calloc(1, sizeof(Tree));
        t->c=c;
        if(root==NULL)
        {
            root=t;
            Rearinsert(Q, t);
            pcur=Q.front->next;
            continue;
        }
        Rearinsert(Q, t);
        if(pcur->e->lchild==NULL)
        {
            pcur->e->lchild=t;
        }
        else if(pcur->e->rchild==NULL)
        {
            pcur->e->rchild = t;
            pcur=pcur->next;
        }
    }
    t=root;
}

void PreOrder(tree t)
{
    if(t!=NULL)
    {
        printf("%c",t->c);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

void InOrder(tree t)
{
    if (t != NULL)
    {
        InOrder(t->lchild);
        printf("%c", t->c);
        InOrder(t->rchild);
    }
}

void PostOrder(tree t)
{
    if (t != NULL)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        printf("%c", t->c);
    }
}

void LevelOrder(tree t)
{
    Queue Q;
    tree detree;
    InitQueue(Q);
    Rearinsert(Q,t);
    while(!IsEmpty(Q))
    {
        Frontdelete(Q,detree);
        printf("%c", detree->c);
        if(detree->lchild!=NULL)
        {
            Rearinsert(Q, detree->lchild);
        }
        if (detree->rchild != NULL)
        {
            Rearinsert(Q, detree->rchild);
        }
    }
}