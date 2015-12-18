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
int degree = 0;

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

void outIndex(BTNode *t, elemType key)
{
	if (t)
	{
		if (t->data == key)
		{
			if (t->lchild != NULL)
			{
				degree++;
			}
			if (t->rchild != NULL)
			{
				degree++;
			}
			return;
		}
		outIndex(t->lchild,key);
		outIndex(t->rchild,key);
	}
}

int main()
{
	BTNode *t;
	elemType key;
	cin >> datas>>key;
	creat(t);
	outIndex(t, key);
	cout << degree;
	return 0;
}