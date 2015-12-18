#include <iostream>
#include <string>
using namespace std;

typedef char elemType;

typedef struct node{
	elemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

string datas;
int i = -1;
int width = 0;

void creat(BTNode *&t)
{
	i++;
	if (datas[i] == '#' || i > datas.size())
	{
		t = NULL;
		return;
	}
	t = new BTNode;
	t->data = datas[i];
	creat(t->lchild);
	creat(t->rchild);
}

void countLeaf(BTNode *t)
{
	if (t)
	{
		if (t->lchild == NULL&&t->rchild == NULL)
		{ 
			width++; 
		}
		countLeaf(t->lchild);
		countLeaf(t->rchild);
	}
}

int main()
{
	cin >> datas;
	BTNode *t;
	creat(t);
	countLeaf(t);
	cout << width;
	return 0;
}