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
	for (i = 0; i < len; i++)
	{
		s = new LinkList;
		s->data = datas[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

int main()
{
	LinkList *m = NULL, *p;
	elemType a[500];
	int lenth, i, key;
	bool find = false;
	cin >> lenth;
	for (i = 0; i < lenth; i++)
	{
		cin >> a[i];
	}
	cin >> key;
	Init(m);
	creat(m, a, lenth);
	p = m->next;
	while (p!=NULL)
	{
		if (p->data == key)
		{
			find = true;
			break;
		}
		p = p->next;
	}
	if (find)
	{
		cout << "OK!";
	} 
	else
	{
		cout << "error!";
	}
	return 0;
}