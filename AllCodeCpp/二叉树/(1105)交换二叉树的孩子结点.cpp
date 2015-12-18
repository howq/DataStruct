#include <iostream>
#include<string>
using namespace std;

typedef char elemType;

typedef struct node
{
	elemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

string datas;
int i = -1;

void creat(BTNode *&t)
{
	i++;
	if (datas[i] == '#' || i > datas.size()){ t = NULL; return; }
	t = new BTNode;
	t->data = datas[i];
	creat(t->lchild);
	creat(t->rchild);
}

void change(BTNode *t)
{
	if (t)
	{
		BTNode *temp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = temp;
		change(t->lchild);
		change(t->rchild);
	}
}

void mid(BTNode *t)
{
	if (t)
	{
		mid(t->lchild);
		cout << t->data;
		mid(t->rchild);
	}
}

void front(BTNode *t)
{
	if (t)
	{
		cout << t->data;
		front(t->lchild);
		front(t->rchild);
	}
}

int main()
{
	BTNode *t;
	cin >> datas;
	creat(t);
	change(t);
	mid(t);
	cout << endl;
	front(t);
	return 0;
}