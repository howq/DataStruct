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

int BTNodeHeight(BTNode *t)
{
	int lchild, rchild;
	if (t == NULL){return 0;}
	else
	{
		lchild = BTNodeHeight(t->lchild);
		rchild = BTNodeHeight(t->rchild);
		return (lchild > rchild) ? (lchild + 1) : (rchild + 1);
	}
}

int main()
{
	cin >> datas;
	BTNode *t;
	creat(t);
	int height = BTNodeHeight(t);
	cout << height;
	return 0;
}