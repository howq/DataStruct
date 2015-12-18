#include <iostream>
using namespace std;

#define MaxSize 512

typedef struct  
{
	char data[MaxSize];
	int top;
}SqList;

void Init(SqList *&L)
{
	L = new SqList;
	L->top = -1;
}

void push(SqList *&L, char key)
{
	if (L->top == MaxSize - 1)
	{
		return;
	}
	L->top++;
	L->data[L->top] = key;
}

void pop(SqList *&L, char &key)
{
	if (L->top == -1)
	{
		return;
	}
	key = L->data[L->top];
	L->top--;
}

void getTop(SqList *L,char &key)
{
	if (L->top == -1)
	{
		return;
	}
	key = L->data[L->top];
}

bool match(SqList *&L,char a[])
{
	int i = 0;
	char key = ' ';
	while (a[i] != '\0')
	{
		getTop(L, key);
		if (a[i] == '[' || a[i] == '(')
		{
			push(L, a[i]);
		} 
		else if (a[i] == ')'&&key == '(')
		{
			pop(L, key);
		}
		else if (a[i] == ']'&&key == '[')
		{
			pop(L, key);
		}
		else
		{
			return false;
		}
		i++;
	}
	if (L->top == -1)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main()
{
	char a[512];
	SqList *m = NULL;
	Init(m);
	cin >> a;
//	gets_s(a);
	if (match(m, a))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}