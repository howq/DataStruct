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
int i = -1, j = 0;
int widths[100] = {0};

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

void BTNodeWidth(BTNode *t, int height)
{
	if (t)
	{
		widths[height]++;
		if (t->lchild == NULL&&t->rchild == NULL)
		{
			return;
		}
		else
		{
			int high = height;
			BTNodeWidth(t->lchild, ++height);
			BTNodeWidth(t->rchild, ++high);
		}
	}
}

int main()
{
	cin >> datas;
	BTNode *t;
	int height = 1, max = 0, i;
	creat(t);
	BTNodeWidth(t, height);
	i = height;
	while (widths[i] != 0)
	{
		if (widths[i] > max)
		{
			max = widths[i];
		}
		i++;
	}
	cout << max;
	return 0;
}