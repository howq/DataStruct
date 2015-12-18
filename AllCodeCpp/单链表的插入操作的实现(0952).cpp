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
	LinkList *s,*r = L;
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

void Insert(LinkList *&L, int index, elemType key)
{
	int i = 0;
	LinkList *p = L,*s;
	while (p != NULL&&i < index - 1)
	{
		p = p->next;
		i++;
	}
	if (p==NULL)
	{
		cout << "error!";
	} 
	else
	{
		s = new LinkList;
		s->data = key;
		s->next = p->next;
		p->next = s;
		showlist(L);
	}
}

int main()
{
	LinkList *m = NULL;
	elemType a[500];
	int lenth,i,index,key;
	cin >> lenth;
	for (i = 0; i < lenth; i++)
	{
		cin >> a[i];
	}
	cin >> index;
	cin >> key;
	Init(m);
	creat(m, a, lenth);
	Insert(m, index, key);
	return 0;
}
