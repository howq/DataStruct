#include <iostream>
#include<string>
using namespace std;
#define MaxSize 512

typedef char elemType;

typedef struct node
{
	elemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

string datas;
int i = -1;
bool isComplete = true;
bool firLeaf = false;

void creat(BTNode *&t)
{
	i++;
	if (datas[i] == '#' || i > datas.size()){ t = NULL; return; }
	t = new BTNode;
	t->data = datas[i];
	creat(t->lchild);
	creat(t->rchild);
}

void is_completeTree(BTNode* t)
{
	BTNode *p;
	BTNode *qu[MaxSize];
	int front, rear;
	front = rear = -1;
	rear++;
	qu[rear] = t;
	while (front != rear)
	{
		front = (front + 1) % MaxSize;
		p = qu[front];

		if (p->lchild == NULL&&p->rchild == NULL&&!firLeaf)
		{
			firLeaf = true;
		}

		if (firLeaf)
		{
			if (!(p->lchild == NULL&&p->rchild == NULL))
			{
				isComplete = false;
			}	
		}			

		if (p->lchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
}

int main()
{
	cin >> datas;
	BTNode *t;
	creat(t);
	is_completeTree(t);
	if (isComplete)
	{
		cout << "Y";
	}
	else
	{
		cout << "N";
	}
	return 0;
}