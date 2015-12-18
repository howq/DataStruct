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
		cout << p->data;
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
	printOut(t);
	return 0;
}