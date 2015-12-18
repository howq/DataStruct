#include<iostream>
using namespace std;

typedef char elemType;

typedef struct node
{
	elemType data;
	node *next;
}LinkList;

/*
//β�巨
void creat(LinkList *&L,elemType a[],int len)
{
	L = new LinkList;
	L->next = NULL;
	LinkList *p,*r = L;
	int i;
	for (i = 0; i < len;i++)
	{
		p = new LinkList;
		p->data = a[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}*/

//ͷ�巨
void creat(LinkList *&L, elemType a[], int len)
{
	L = new LinkList;
	L->next = NULL;
	LinkList *p;
	int i;
	for (i = 0; i < len; i++)
	{
		p = new LinkList;
		p->data = a[i];
		p->next = L->next;
		L->next = p;
	}
}

void output(LinkList *L)
{
	LinkList *s = L->next;
	while (s != NULL)
	{
		cout << s->data;
		s = s->next;
		if (s != NULL)
			cout << " ";
	}
}

int main()
{
	int lenth,i;
	elemType m[500];
	LinkList *show;
	cin >> lenth;
	for (i = 0; i < lenth; i++)
	{
		cin >> m[i];
	}
	creat(show, m, lenth);
	output(show);
	return 0;
}
