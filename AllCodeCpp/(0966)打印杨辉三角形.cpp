/*
#include<iostream>
using namespace std;
#include <stdio.h>
#include <malloc.h>

#define MaxSize 100

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;  //队首和队尾指针
} SqQueue;

void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
void ClearQueue(SqQueue *&q)
{
	free(q);
}
int QueueEmpty(SqQueue *q)
{
	return(q->front == q->rear);
}
int enQueue(SqQueue *&q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front)  //队满
		return 0;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return 1;
}
int deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear)  //队空
		return 0;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return 1;
}


int peek(SqQueue *&q, ElemType &e)
{
	int i;
	if (q->front == q->rear)  //队空
		return 0;
	i = (q->front + 1) % MaxSize;
	e = q->data[i];
	return 1;
}


void yang(int n)
{
//	int i,j;
	SqQueue *L;
	InitQueue(L);
//	ElemType a[MaxSize][MaxSize] = {'\0'};
//	ElemType key;
	enQueue(L,1);
	int i, j, y, x;
	for (i = 2; i <= n + 1; i++)
	{
		enQueue(L, 1);
		for (j = 1; j <= i - 2; j++)
		{
			deQueue(L, x);
			cout << x << " ";
			peek(L, y);
			enQueue(L, x + y);
		}
		deQueue(L, x);
		cout << x;
		enQueue(L, 1);
		cout << "\r\n";
	}
	ClearQueue(L);
}


int main()
{
	int n;
	cin >> n;
	yang(n);
	return 1;
}*/

#include"iostream"
using namespace std;
#include "stdio.h"
#include"stdlib.h"
typedef struct sq
{
	int data[500];
	int front, rear;

}Q;
void init(Q *&q)
{
	q = (Q *)malloc(sizeof(Q));
	q->front = -1;
	q->rear = -1;
}//³õÊ¼»¯
void en(Q *&q, int x)
{
	if ((q->rear + 1) % 500 == q->front)
	{
		cout << "error!";
		exit(0);
	}
	q->rear = (q->rear + 1) % 500;
	q->data[q->rear] = x;
}//Èë¶ÓÁÐ
void chu(Q *&q, int &m)
{
	if (q->rear == q->front)
	{
		cout << "error!";
		exit(0);
	}
	q->front = (q->front + 1) % 500;
	m = q->data[q->front];
}//³ö¶ÓÁÐ
void qu(Q *&q, int &m)
{
	if (q->rear == q->front)
	{
		cout << "error!";
		exit(0);
	}
	int i = (q->front + 1) % 500;
	m = q->data[i];
}//È¡ÔªËØ
void yang(int n)
{
	Q *p;
	int a, e, i = 1;
	init(p);
	cout << "1";
	cout << "\r\n";
	en(p, 0);
	en(p, 1);
	en(p, 0);
	while (i != n)
	{
		chu(p, a);
		qu(p, e);
		if (e != 0)
		{
			cout << a + e << " ";
			en(p, a + e);
		}
		else
		{
			cout << a + e;
			cout << "\r\n";
			en(p, a + e);
			en(p, 0);
			i++;
		}
	}

}
int main()
{
	Q *p;
	int m;
	cin >> m;
	init(p);
	yang(m);
	return 1;
}