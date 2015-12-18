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
int times = 0;

void creat(BTNode *&t)
{
	i++;
	if (datas[i] == '#' || i > datas.size()){ t = NULL; return; }
	t = new BTNode;
	t->data = datas[i];
	creat(t->lchild);
	creat(t->rchild);
}

void count(BTNode *t)
{
	if (t)
	{
		if (t->lchild != NULL&&t->rchild != NULL)
		{
			times++;
		}
		count(t->lchild);
		count(t->rchild);
	}
}

int main()
{
	cin >> datas;
	BTNode *t;
	creat(t);
	count(t);
	cout << times;
	return 0;
}