#include <iostream>
using namespace std;

typedef int elemType;

typedef struct node{
	elemType data;
	node *next;
}LinkList;

void creat(LinkList *&L, elemType a[], int len)
{
	int i;
	L = new LinkList;
	LinkList *s, *r = L;
	for (i = 0; i < len; i++)
	{
		s = new LinkList;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void deleteKey(LinkList *L, elemType key)
{
	LinkList *s = L->next,*pre = L;
	while (s!=NULL)
	{
		if (s->data == key)
		{
			pre->next = s->next;		//删除元素后pre未移动
		}
		else     //删除多个元素
		{
			pre = pre->next;		
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
		if (s!=NULL)
		{
			cout << " ";
		}
	}
}
bool isEmpty(LinkList *L)
{
	return L->next == NULL;
}

int main()
{
	int len, i;
	elemType a[500],key;
	LinkList *m;
	cin >> len;
	for (i = 0; i < len; i++)
	{
		cin>>a[i];
	}
	cin >> key;
	creat(m, a, len);
	deleteKey(m, key);
	if (isEmpty(m))
	{
		cout << -1;
	}
	else
	{
		show(m);
	}
	return 0;
}