#include<iostream>
using namespace std;

typedef int elemType;

typedef struct node
{
	node *pre;
	elemType data;
	node *next;
}DLinkList;
void showlist(DLinkList *L);
void creat(DLinkList *&L, elemType datas[], int len)
{
	L = new DLinkList;
	L->pre = NULL;
	L->next = NULL;
	DLinkList *s, *r = L;
	int i;
	for (i = 0; i < len; i++)
	{
		s = new DLinkList;
		s->data = datas[i];
		s->pre = r;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void showlist(DLinkList *L)
{
	DLinkList *p = L->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
		if (p != NULL)
			cout << " ";
	}
}


void sort(DLinkList *&L)
{
	DLinkList *p = L->next, *r;
	while (p!= NULL)
	{
		r = p->next;
		while (r != NULL)
		{
			if (p->data > r->data)
			{
				DLinkList *temp = p->pre;

				p->pre->next = p->next;
				p->next->pre = p->pre;

				if (r->next != NULL)
				{
					r->next->pre = p;
				}
				p->next = r->next;

				r->next = p;
				p->pre = r;

				p = temp;
			}
			r = r->next;
		}
		p = p->next;
	}
}

int main()
{
	DLinkList *m = NULL;
	elemType a[500];
	int lenth, i;
	cin >> lenth;
	for (i = 0; i < lenth; i++)
	{
		cin >> a[i];
	}
	creat(m,a,lenth);
	sort(m);
	showlist(m);
	return 0;
}
