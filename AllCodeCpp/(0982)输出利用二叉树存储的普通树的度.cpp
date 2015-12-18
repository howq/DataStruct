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
int index = -1;
int treeTimes = 0, hight = 0;
int widths[100] = { 1 };

void creat(BTNode *&t)
{
	index++;
	if (datas[index] == '#' || index > datas.size())
	{
		t = NULL;
		return;
	}
	t = new BTNode;
	t->data = datas[index];
	creat(t->lchild);
	creat(t->rchild);
}

void treeCount(BTNode *t)
{
	if (t)
	{
		treeTimes++;
		treeCount(t->rchild);
	}
}

void treeDigree(BTNode *t,int height)
{
	if (treeTimes > 1)
	{
		cout << "ERROR";
		return;
	}
	if (t)
	{
		if (t->lchild == NULL&&t->rchild == NULL)
		{
			return;
		}
		else
		{
			if (t->lchild != NULL)
			{
				height++;
			}
			//int high = height;
			treeDigree(t->lchild, height);
			if (t->rchild != NULL)
			{
				widths[height]++;
			}
			treeDigree(t->rchild, height);
		}
	}
}

/*
int main()
{
	cin >> datas;
	BTNode *t;
	int height = 1,i = height;
	int max = 0;
	creat(t);
	treeCount(t);
	treeDigree(t, height);
	while (widths[i] != 0)
	{
		if (widths[i] > max)
		{
			max = widths[i];
		}
		i++;
	}
	cout << max - 1;
	return 0;
}*/