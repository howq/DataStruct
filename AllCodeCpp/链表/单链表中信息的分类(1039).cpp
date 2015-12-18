#include <iostream>
using namespace std;

typedef char elemType;

typedef struct node{
	elemType data;
	node *next;
}LinkList;

void init(LinkList *&L)
{
	L = new LinkList;
	L->next = NULL;
}

void creat(LinkList *&L)
{
	elemType a[500];
	LinkList *s, *r = L;
	int i = 0;
	cin.getline(a, 500);
	while (a[i]!='\0')
	{
		s = new LinkList;
		s->data = a[i];
		r->next = s;
		r = s;
		i++;
	}
	r->next = NULL;
}

void show(LinkList *L)
{
	LinkList *s = L->next;
	while (s!=NULL)
	{
		cout << s->data;
		s = s->next;
	}
}

void change(LinkList *L)
{
	LinkList *letter, *num, *charL,*s = L->next,*m;
	init(letter);
	init(num);
	init(charL);
	LinkList *i = letter, *j = num, *k = charL;
	while (s != NULL)
	{
		m = new LinkList;
		m->data = s->data;
		if ((s->data >= 'a'&&s->data <= 'z')
			|| (s->data >= 'A'&&s->data <= 'Z'))
		{
			i->next = m;
			i = m;
		}
		else if (s->data >= '0'&&s->data <= '9')
		{
			j->next = m;
			j = m;
		}
		else
		{
			k->next = m;
			k = m;
		}
		m->next = NULL;
		s = s->next;
	}
	show(num);
	cout << endl;
	show(letter);
	cout << endl;
	show(charL); 
	cout << endl;
}

int main()
{
	LinkList *L;
	init(L);
	creat(L);
	change(L);
	return 0;
}