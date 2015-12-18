#include <iostream>
using namespace std;

typedef int elemType;

typedef struct node
{
	elemType data;
	node *next;
}LinkList;

void creat(LinkList *&L, elemType a[], int len)
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

void add(LinkList *&L)
{
	LinkList *s = L->next->next, *r = L->next;
	elemType key = L->next->data;
	while (s != NULL)
	{
		LinkList *temp = s->next;
		if (s->data <= key)
		{
			s->next = L->next;
			L->next = s;
		}
		else
		{
//			s->next = r->next;
			r->next = s;
			s->next = NULL;
			r = s;
		}
		s = temp;
	}
}

void show(LinkList *L)
{
	LinkList *s = L->next;
	while (s!=NULL)
	{
		cout << s->data;
		s = s->next;
		if (s!=NULL)
		{
			cout << " ";
		}
	}
}

int main()
{
	LinkList *m;
	int len, i;
	elemType a[500];
	cin >> len;
	for (i = 0; i < len;i++)
	{
		cin >> a[i];
	}
	creat(m, a, len);
	add(m);
	show(m);
	return 0;
}
