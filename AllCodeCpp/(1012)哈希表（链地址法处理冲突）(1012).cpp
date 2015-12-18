#include<iostream>
using namespace std;
#define  max 60
typedef int elemType;

typedef struct node{
	elemType data;
	node *next;
}Hash;

Hash *ht[max];
int p, n;

void create()
{
	Hash *t;
	int i, j;
	for (i = 0; i < n; i++) ht[i] = NULL;
	for (i = 0; i < n; i++)
	{
		t = new Hash;
		cin >> t->data;
		j = t->data%p;
		t->next = ht[j];   //将t结点插入到ht[j]之后;
		ht[j] = t;
	}
}

void search(int key)
{
	int k, c = 0;
	k = key%p;
	Hash *t;
	t = ht[k];
	while (t != NULL&&t->data != key)
	{
		c++;
		t = t->next;
	}
	if (t == NULL)
	{
		cout << -1;
	}
	else
	{
		cout << k << ',' << c;
	}
}

int main()
{
	int k;
	cin >> p;
	cin >> n;
	create();
	cin >> k;
	search(k);
	return 0;
}



/*
void Init(LinkList *&L)
{
	L = new LinkList;
	L->next = NULL;
}

void creat(LinkList *&L, elemType datas[], int lenth)
{
	LinkList *p, *r = L;
	int i;
	for (i = 0; i < lenth; i++)
	{
		p = new LinkList;
		p->data = datas[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
*/
