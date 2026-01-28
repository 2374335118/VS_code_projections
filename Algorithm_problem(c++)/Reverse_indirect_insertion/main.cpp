
#include <math.h>
#include <iostream>

typedef int ElementType;

typedef struct LNode
{
    ElementType data;
    struct LNode *next;
} LNode, *LinkList;

bool List_head_Insert(LinkList &L)
{
    ElementType x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    LinkList s;
    while (x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return true;
}

void Printlist(LinkList L)
{
    L = L->next;
    while (L)
    {
        printf("%-3d ", L->data);
        L = L->next;
    }
    printf("\n");
}

void Middle_Node(LinkList L, LinkList &L2) // 找到链表的中间节点,并且分为L和L2两个链表
{
    L2 = (LinkList)malloc(sizeof(LNode));
    LinkList ppre, pcur;
    ppre = pcur = L->next;
    while (pcur)
    {
        pcur = pcur->next;
        if (pcur == NULL)
        {
            break;
        }
        pcur = pcur->next;
        if (pcur == NULL)
        {
            break;
        }
        ppre = ppre->next;
    }
    L2->next = ppre->next;
    ppre->next = NULL;
}

void Reverse_List2(LinkList &L2) // 将链表L2反转
{
    LinkList p, q, r;
    p = L2->next;
    if (p == NULL)
    {
        return;
    }
    q = p->next;
    if (q == NULL)
    {
        return;
    }
    r = q->next;
    while (r)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    L2->next->next = NULL;
    L2->next = q;
}

void InSertL_and_L2(LinkList L, LinkList L2) // 将L2链表插入到L链表中
{
    LinkList p, q, r;
    r = L->next;
    p = r->next;
    if (p == NULL)
    {
        return;
    }
    q = L2->next;
    if (q == NULL)
    {
        return;
    }
    while (p && q)
    {
        r->next = q;
        q = q->next;
        r = r->next;
        r->next = p;
        p = p->next;
        r = r->next;
    }

    // 处理剩余节点
    if (p != NULL)
    {
        r->next = p;
    }
    if (q != NULL)
    {
        r->next = q;
    }
}

int main()
{
    LinkList L, L2;
    List_head_Insert(L);
    Printlist(L);
    printf("-----------------------------\n");
    Middle_Node(L, L2);
    Printlist(L);
    Printlist(L2);
    printf("-----------------------------\n");
    Reverse_List2(L2);
    Printlist(L2);
    printf("-----------------------------\n");
    InSertL_and_L2(L, L2);
    Printlist(L);
    return 0;
}