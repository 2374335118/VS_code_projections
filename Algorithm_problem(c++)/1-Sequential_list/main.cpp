#include <stdio.h>
#include <stdlib.h>
// 顺序表的初始化和插入操作

#define MAXSIZE 50

typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} SqList;

void InitList(SqList &L)
{
	L.length = 0;
}

bool ListInsert(SqList &L, int pos, ElemType date)
{
	// 判断插入位置pos是否合法
	if (pos < 1 || pos > L.length)
	{
		return false;
	}
	else
	{
		// 将data插入位置pos，后面的元素依次后移
		for (int j = L.length; pos <= j; j--)
		{
			L.data[j] = L.data[j - 1]; // pos位置及之后的元素后移
		}
		L.length++;				// 表长增1
		L.data[pos - 1] = date; // 插入元素
	}
}

bool ListDelete(SqList

					&L,
				int pos)
{
	// 判断删除位置pos是否合法
	if (pos < 1 || pos > L.length)
	{
		return false;
	}
	else
	{
		for (int j = pos + 1; j <= L.length; j++)
		{
			L.data[j - 2] = L.data[j - 1]; // pos位置之后的元素前移
		}
		L.length--; // 表长减1
	}
}

void PrintList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%3d", L.data[i]);
	}
	printf("\n");
}

int main()
{
	SqList L;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.data[3] = 4;
	L.data[4] = 5;
	L.data[5] = 6;
	L.data[6] = 7;
	L.length = 7;
	int a;
	scanf("%d", &a);
	bool retin = ListInsert(L, 2, a);
	if (retin)
	{
		printf("插入成功\n");
		PrintList(L);
	}
	else
	{
		printf("插入失败\n");
	}

	int c;
	scanf("%d", &c);
	bool retdel = ListDelete(L, c);
	if (retdel)
	{
		printf("删除成功\n");
		PrintList(L);
	}
	else
	{
		printf("删除失败\n");
	}
	return 0;
}
