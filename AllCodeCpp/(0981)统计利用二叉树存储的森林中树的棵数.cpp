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
int times = 0;

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
		times++;
		treeCount(t->rchild);
	}
}

int main()
{
	cin >> datas;
	BTNode *t;
	creat(t);
	treeCount(t);
	cout << times;
	return 0;
}