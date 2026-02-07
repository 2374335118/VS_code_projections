#include"function.h"

void PreOrder(tree t)//前序遍历、先序遍历、深度优先遍历
{
    if(t!=NULL)
    {
        printf("%c", t->e);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

void InOrder(tree t)//中序 
{
    if(t!=NULL)
    {
        InOrder(t->lchild);
        printf("%c",t->e);
        InOrder(t->rchild);
    }
}

void PostOrder(tree t)//后序
{
    if(t!=NULL)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        printf("%c",t->e);
    }
}

void LevelOrder(tree t)
{
    Queue Q;
    InitQueue(Q);
    tree p;//存储出队的节点
    RearInsert(Q,t);
    while(!Isempty(Q))
    {
        FrontDelete(Q,p);
        printf("%c",p->e);
        if(p->lchild!=NULL)
        {
            RearInsert(Q,p->lchild);
        }
        if(p->rchild!=NULL)
        {
            RearInsert(Q,p->rchild);
        }
    }
}
int main()
{
    tree pnew;//申请树的一个新节点
    tree root=NULL;//树根为空代表空树
    char c;
    Queue queuenew;
    LinkList pcur=(LinkList)calloc(1,sizeof(Node));
    InitQueue(queuenew);
    while(scanf("%c",&c))
    {
        if(c=='\n')
        {
            break;//scanf读到换行符就结束
        }
        pnew=(tree)calloc(1,sizeof(Tree));//calloc申请树节点空间同时初始化NULL，空间大小为1*sizeof(Tree)
        pnew->e=c;
        if(root==NULL)
        {
            root=pnew;
            RearInsert(queuenew, pnew);
            pcur->data=pnew;
            pcur=queuenew.rear;
        }
        else
        {
            //尾插入队
            RearInsert(queuenew, pnew);
            //queuenew入树
            if(pcur->data->lchild==NULL)
            {
                pcur->data->lchild=pnew;
            }
            else if (pcur->data->rchild == NULL)
            {
                pcur->data->rchild=pnew;
                pcur=pcur->next;
            }
        }
    }
    // abcdefghij
    printf("-------------------------------先序遍历结果-------------------------------------\n");
    PreOrder(root);
    printf("\n-------------------------------中序遍历结果-------------------------------------\n");
    InOrder(root);
    printf("\n-------------------------------后序遍历结果-------------------------------------\n");
    PostOrder(root);
    printf("\n-------------------------------层序遍历结果-------------------------------------\n");
    LevelOrder(root);
    return 0;
}