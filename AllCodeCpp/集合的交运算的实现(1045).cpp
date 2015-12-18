#include <iostream>
using namespace std;

typedef int elemType;

typedef struct node{
	elemType data;
	node *next;
}LinkList;
void show(LinkList *L);
void creat(LinkList *&L, elemType a[], int len)
{
	L = new LinkList;
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

bool exist(LinkList *L, elemType key)
{
	LinkList *s = L->next;
	while (s != NULL)
	{
		if (s->data == key)
		{
			return true;
		}
		s = s->next;
	}
	return false;
}

void add(LinkList *&L, LinkList *last)
{
	LinkList *s = last->next;
	LinkList *newList = new LinkList;
	LinkList *r = L->next, *low = newList;
	while (s != NULL)
	{
		if (exist(L, s->data))
		{
			low->next = s;
			low = s;
		}
		else
		{
			low->next = NULL;
		}
		s = s->next;
	}
	show(newList);
}

void show(LinkList *L)
{
	LinkList *s = L->next;
	while (s != NULL)
	{
		cout << s->data;
		s = s->next;
		if (s != NULL)
		{
			cout << " ";
		}
	}
}

int main()
{
	int len1, len2;
	LinkList *m, *n;
	elemType a[500], b[500];
	int i;
	cin >> len1;
	for (i = 0; i < len1; i++)
	{
		cin >> a[i];
	}
	cin >> len2;
	for (i = 0; i < len2; i++)
	{
		cin >> b[i];
	}
	creat(m, a, len1);
	creat(n, b, len2);
	add(n, m);
	return 0;
}