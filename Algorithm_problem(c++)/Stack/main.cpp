#include <stdio.h>
#include <iostream>
#include <math.h>

#define MAXSIZE 50

typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE]; // 数组
    int top;                // 栈顶变量
} Stack;

void InitStack(Stack &S)
{
    S.top = -1; // 栈顶指向-1，表示空栈
}

bool StackEmpty(Stack S) // 判断栈空。
{
    if (S.top == -1)
        return true;
    else
        return false;
}

bool Push(Stack &S, ElemType e) // 入栈
{
    // 判断栈满
    if (S.top == MAXSIZE - 1)
    {
        return false;
    }
    S.data[++S.top] = e;
    return true;
}

bool GetTop(Stack S, ElemType &x) // 取栈顶元素
{
    if (StackEmpty(S))
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

bool Pop(Stack &S, ElemType &x) // 出栈
{
    if (StackEmpty(S))
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

int main()
{
    Stack S;
    InitStack(S);
    bool flag;
    flag = StackEmpty(S);
    if (flag)
    {
        printf("Stack is empty\n");
    }
    Push(S, 10);
    Push(S, 20);
    Push(S, 30);
    ElemType x;
    GetTop(S, x);
    flag = GetTop(S, x);
    if (flag)
    {
        printf("Top element is %d\n", x);
    }
    flag = Pop(S, x);
    if (flag)
    {
        printf("Popped element is %d\n", x);
    }
}