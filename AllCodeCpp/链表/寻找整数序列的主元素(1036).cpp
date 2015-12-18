#include <iostream>
using namespace std;

typedef int elemType;

typedef struct node
{
	elemType data;
	node *next;
}LinkList;

void creat(LinkList *&L, elemType a[],int len)
{
	L = new LinkList;
	L->next = NULL;
	LinkList *s, *r = L;
	int i;
	for (i = 0; i < len; i++)
	{
		s = new LinkList;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void findMain(LinkList *L)
{
	LinkList *s = L->next,*r;
	elemType mainElem;
	int times = 0,allTime = 0;
	bool find = false;
	while (s != NULL)
	{
		allTime++;
		s = s->next;
	}
	s = L->next;
	while (s != NULL&&!find)
	{
		r = s->next;
		mainElem = s->data;
		times = 1;
		while (r != NULL)
		{
			if (mainElem == r->data)
			{
				times++;
			}
			r = r->next;
		}
		if (times > allTime / 2)
		{
			find = true;
			break;
		}
		s = s->next;
	}
	if (find)
	{
		cout << mainElem;
	} 
	else
	{
		cout << -1;
	}
}

int main()
{
	int i, len;
	LinkList *m;
	elemType a[500];
	cin >> len;
	for (i = 0; i < len; i++)
	{
		cin>>a[i];
	}
	creat(m, a, len);
	findMain(m);
	return 0;
}