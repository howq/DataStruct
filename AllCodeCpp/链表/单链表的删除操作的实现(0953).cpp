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

void Delete(LinkList *&L, int index)
{
	int i = 0;
	LinkList *p = L;
	while (p != NULL&&i < index - 2)
	{
		p = p->next;
		i++;
	}
	if (p->next->next == NULL || index < 2)
	{
		cout << "error!";
	}
	else
	{
		p->next = p->next->next;
		showlist(L);
	}
}

int main()
{
	LinkList *m = NULL;
	elemType a[500];
	int lenth, i, index;
	cin >> lenth;
	for (i = 0; i < lenth; i++)
	{
		cin >> a[i];
	}
	cin >> index;
	if (index <= 1 || index>lenth)
		cout << "error!";
	else
	{
		Init(m);
		creat(m, a, lenth);
		Delete(m, index);
	}
	return 0;
}