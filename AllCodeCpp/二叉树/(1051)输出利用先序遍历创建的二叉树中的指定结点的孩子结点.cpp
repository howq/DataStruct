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

void printOut(BTNode *t,elemType key)
{
	if (t)
	{
		if (t->data == key)
		{
			elemType l,r;
			if (t->lchild==NULL)
			{
				l = '#';
			}
			else
			{
				l = t->lchild->data;
			}
			if (t->rchild == NULL)
			{
				r = '#';
			}
			else
			{
				r = t->rchild->data;
			}
			cout << "L:" << l << "," << "R:" << r;
			return;
		}
		printOut(t->lchild,key);
		printOut(t->rchild,key);
	}
}

int main()
{
	BTNode *t;
	elemType key;
	cin >> datas>>key;
	creat(t);
	printOut(t,key);
	return 0;
}