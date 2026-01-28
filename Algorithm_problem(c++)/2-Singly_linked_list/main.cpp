#include <stdio.h>
#include <iostream>
#include <string>

#define MAXSIZE 100;
typedef int ElemType;

typedef struct LNode
{
	ElemType date;
	struct LNode *next;
} LNode, *LinkList;

void list_head_insert(LinkList &L) // 头插法建立单链表
{
	L = (LinkList)malloc(sizeof(LNode)); // 申请头结点空间,并使L指向头结点
	L->next = NULL;						 // 头结点的指针域置为空
	ElemType x;
	scanf("%d", &x);
	LinkList s; // 创建结点s

	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode)); // 申请下一个结点空间
		s->date = x;
		s->next = L->next; // 新结点指向原来的第一个结点
		L->next = s;	   // 头结点指向新结点
		scanf("%d", &x);
	}
}

void list_end_insert(LinkList &L) // 尾插法建立单链表
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	ElemType x;
	scanf("%d", &x);
	LinkList s, r = L; // s指向新结点,r为指向尾结点的指针(初始化赋予r头节点L的首地址，让其共享L所指向结构体空间)
	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->date = x;
		r->next = s; // 尾结点指向新结点
		r = s;		 // r指向新的尾结点
		scanf("%d", &x);
	}
	r->next = NULL; // 尾结点指针域置为空
}

void print_list(LinkList L)
{
	L = L->next; // 由于L一开始存储头节点地址，所以打印初始化要往前推一个节点
	while (L != NULL)
	{
		printf("%-3d", L->date);
		L = L->next;
	}
	printf("\n");
}

LinkList GetElem(LinkList L, int SearchPos) // 按位查找
{
	int i = 0;
	while (i < SearchPos && L)
	{
		L = L->next;
		i++;
	}
	return L;
}

LinkList LocateElem(LinkList L, ElemType e) // 按值查找
{
	while (L && L->date != e)
	{
		L = L->next;
	}

	return L;
}

bool ListFronInsert(LinkList L, int pos, ElemType e) // 在第pos个位置前插入元素e
{
	LinkList p = GetElem(L, pos - 1); // 获取第pos-1个元素
	if (p == NULL)
	{
		return false;
	}
	LinkList s = (LinkList)malloc(sizeof(LNode)); // 申请新插入结点空间
	s->date = e;
	s->next = p->next; // 新结点指向原第pos个结点
	p->next = s;	   // 第pos-1个结点指向新结点
	return true;
}

bool ListDelet(LinkList L, int Pos) // 删除第Pos位置的节点
{
	LinkList p = GetElem(L, Pos - 1); // 获取目标节点前一个节点指针并赋给p
	if (p == NULL)
	{
		return false;
	}
	LinkList q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

int main()
{
	LinkList L, search;
	list_end_insert(L); // 尾插法建立单链表
	print_list(L);		// 遍历打印链表
	// search = GetElem(L, 2);//获取第2个元素
	// if (search != NULL)
	//{
	//	printf("\nThe 2nd element is %d\n", search->date);
	// }
	// else
	//{
	//	printf("\nThe 2nd element is not exist\n");
	// }

	// ListFronInsert(L, 4, 99);
	// print_list(L);//遍历打印链表
	ListDelet(L, 4);
	print_list(L); // 遍历打印链表
	return 0;
}