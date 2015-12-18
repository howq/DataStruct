#include <iostream>
using namespace std;

typedef int elemType;

typedef struct node{
	elemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;


int num = 0;

void Insert(BTNode *&t,elemType x)
{
	if (t == NULL)
	{
		t = new BTNode;
		t->data = x;
		t->lchild = NULL;
		t->rchild = NULL;
		return;
	}
	else if (x < t->data)
	{
		Insert(t->lchild, x);
	}
	else
	{
		Insert(t->rchild, x);
	}
}

int find(BTNode *t,elemType key)
{
	num++;
	if (key == t->data)
	{
		return 1;
	}
	else if (key < t->data)
	{
		if (t->lchild != NULL)
			return find(t->lchild, key);
		return 0;
	}
	else
	{
		if (t->rchild != NULL)
			return find(t->rchild, key);
		return 0;
	}
}
int main()
{
	elemType datas[512];
	int size;
	BTNode *t =NULL;
	int i;
	elemType key;
	cin >> size;
	for (i = 0; i < size; i++)
	{
		cin >> datas[i];
		Insert(t, datas[i]);
	}
	cin >> key;
	if (find(t, key))
	{
		cout << num;
	}
	else
	{
		cout << -1;
	}
	return 0;
}