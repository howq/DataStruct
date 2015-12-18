#include<iostream>
using namespace std;

typedef char elemType;

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
	for (i = 0; i < len; i++)
	{
		s = new LinkList;
		s->data = datas[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void showlist(LinkList *L)
{
	LinkList *p = L->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
		if (p != NULL)
			cout << " ";
	}
}

int main()
{
	LinkList *m = NULL,*n = NULL,*s;
	elemType a[500],b[500];
	int lenth, i;
	int lenth2;
	cin >> lenth;
	for (i = 0; i < lenth; i++)
	{
		cin >> a[i];
	}
	cin >> lenth2;
	for (i = 0; i < lenth2; i++)
	{
		cin >> b[i];
	}
	Init(m);
	Init(n);
	creat(m, a, lenth);
	creat(n, b, lenth2);
	i = 0;
	s = m;
	while (s->next != NULL)
	{
		s = s->next;
		i++;
	}
	s->next = n->next;
	showlist(m);
	return 0;
}