#include<iostream>
using namespace std;

typedef int elemType;

typedef struct node
{
	elemType data;
	node *next;
}LinkList;

void Init(LinkList *&L)
{
	L = new LinkList;
	L->next = NULL;
}

void creat(LinkList *&L, elemType datas[], int len)
{
	LinkList *s, *r = L;
	int i;
	L->data = datas[0];
	for (i = 1; i < len - 1; i++)
	{
		s = new LinkList;
		s->data = datas[i];
		r->next = s;
		r = s;
	}
	r->next = L;
}


void find(LinkList *L, int key)
{
	int i = 1;
//	LinkList *p = L;
	while (L != L->next)
	{
		if (i == key - 1)
		{
			L = L->next->next;
			i = 0;
		}
		else
		{
			L = L->next;
		}
		i++;
	}
	cout << L->data;
}

int main()
{
	LinkList *m = NULL;
	elemType a[500];
	int lenth, i,key;
	cin >> lenth;
	for (i = 0; i < lenth; i++)
	{
		a[i] = i+1;
	}
	cin >> key;
	Init(m);
	creat(m, a, lenth);
	find(m, key);
	return 0;
}

/*
#include <iostream>
using namespace std;
int main()
{
	int n, m, i, s = 0;
	while (cin >> n >> m&&n != 0 && m != 0)
	{
		s = 0;
		for (i = 2; i <= n; i++)
			s = (s + m) % i;
		cout << s + 1;
	}
	return 0;
}
*/