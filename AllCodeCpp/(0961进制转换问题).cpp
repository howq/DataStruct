#include <iostream>
using namespace std;

#define MaxSize 512

typedef int elemType;

typedef struct 
{
	elemType data[MaxSize];
	int top;
}SqStack;

void init(SqStack *&L)
{
	L = new SqStack;
	L->top = -1;
}

void push(SqStack *&L,elemType key)
{
	if (L->top == MaxSize - 1)
	{
		return;
	}
	L->top++;
	L->data[L->top] = key;
}

void pop(SqStack *&L,elemType &key)
{
	if (L->top == -1)
	{
		return;
	}
	key = L->data[L->top];
	L->top--;
}

void change(SqStack *&L,elemType n)
{
	elemType m, key;
	while (n != 0)
	{
		m = n % 2;
		push(L, m);
		n = n / 2;
	}
	while (L->top != -1)
	{
		pop(L, key);
		cout << key;
	}
}

int main()
{
	SqStack *m = NULL;
	elemType old;
	init(m);
	cin >> old;
	change(m, old);
	return 0;
}