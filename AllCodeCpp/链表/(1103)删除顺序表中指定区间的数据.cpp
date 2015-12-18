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

void mult(LinkList *&L,elemType key1,elemType key2)
{
	LinkList *s = L->next, *r = L;
	while (s != NULL)
	{
		if (s->data >= key1&&s->data <= key2)
		{
			r->next = s->next;
		}
		else
		{
			r = r->next;
		}
		s = s->next;
	}
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
	LinkList *m;
	int len, i;
	elemType a[500], key1, key2;
	cin >> len;
	for (i = 0; i < len; i++)
	{
		cin >> a[i];
	}
	cin >> key1 >> key2;
	creat(m, a, len);
	mult(m, key1, key2);
	show(m);
	return 0;
}
