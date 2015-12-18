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

void printOut(BTNode *t)
{
	if (t)
	{
		printOut(t->lchild);
		printOut(t->rchild);
		cout << t->data;
	}
}

int main()
{
	cin >> datas;
	BTNode *t;
	creat(t);
	printOut(t);
	return 0;
}