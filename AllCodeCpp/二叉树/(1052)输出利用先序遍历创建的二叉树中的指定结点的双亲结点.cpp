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

void printOut(BTNode *t, elemType key)
{
	if (t->data==key)
	{
		cout << '#';
		return;
	}
	if (t->lchild != NULL)
	{
		if (t->lchild->data == key)
		{
			cout << t->data;
			return;
		}
		printOut(t->lchild, key);
	}
	if (t->rchild != NULL)
	{
		if (t->rchild->data == key)
		{
			cout << t->data;
			return;
		}
		printOut(t->rchild, key);
	}
}

int main()
{
	BTNode *t;
	elemType key;
	cin >> datas >> key;
	creat(t);
	printOut(t, key);
	return 0;
}