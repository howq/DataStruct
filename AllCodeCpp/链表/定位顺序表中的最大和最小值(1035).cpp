#include <iostream>
using namespace std;

typedef int elemType;

typedef struct node
{
	elemType data;
	node *next;
}LinkList;

void creat(LinkList *&L,elemType a[],int len)
{
	L = new LinkList;
	L->next = NULL;
	LinkList *s,*r = L;
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

void maxAndmin(LinkList *L)
{
	LinkList *s = L->next;
	elemType max = s->data, min = s->data;
	int maxL = 0, minL = 0, index = 0;
	while (s!=NULL)
	{
		if (s->data > max)
		{
			max = s->data;
			maxL = index;
		}
		else
		{
			min = s->data;
			minL = index;
		} 
		index++;
		s = s->next;
	}
	cout << "Lmax=" << maxL<<"\r\n";
	cout << "Lmin=" << minL;
}

int main()
{
	LinkList *m;
	elemType a[500];
	int i, len;
	cin >> len;
	for (i = 0; i < len; i++)
	{
		cin >> a[i];
	}
	creat(m, a, len);
	maxAndmin(m);
	return 0;
}