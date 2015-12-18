#include<iostream>
using namespace std;

#define MaxSize 512

typedef char elemType


//顺序表
typedef struct MyList{
	elemType datas[MaxSize];
	int size;
};

void Init(MyList *&L)
{
	L->size = 0;
}

//链表
typedef struct node
{
	elemType data;
	node *next;
}LinkList;
//尾插法
void creat(LinkList *&L,elemType datas,int len)
{
	L = new LinkList；
	L->next = NULL;
	LinkList *s,*r = L;
	for (i = 0; i < len; i++)
	{
		s = new LinkList;
		s->data = datas[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
//头插法
void creat(LinkList *&L,elemType datas,int len)
{
	L = new LinkList；
	L->next = NULL;
	LinkList *p;
	for (i = 0; i < len; i++)
	{
		p = new LinkList;
		p->data = datas[i];
		p->next = L->next;
		L->next = p;
	}
}

void show(LinkList *L)
{
	LinkList *s = L->next;
	while (s != NULL)
	{
		cout << s->data;
		s = s->next;
		if (s != NULL)
			cout << " ";
	}
}

//树
typedef struct node{
	elemType data;
	struct node *lchild;
	struct node *rchild;
}TBNode;

string datas;
int index = -1;

void creat(TBNode *&t)
{
	index++;
	if(datas[index] = '#'||index > datas.size()){t = NULL; return;}
	else
	{
		t = new TBNode;
		t->data = datas[index];
		creat(t->lchild);
		creat(t->rchild);
	}
}

//栈
typedef struct  
{
	char data[MaxSize];
	int top;
}SqList;

void Init(SqList *&L)
{
	L = new SqList;
	L->top = -1;
}

void push(SqList *&L, char key)
{
	if (L->top == MaxSize - 1)
	{
		return;
	}
	L->top++;
	L->data[L->top] = key;
}

void pop(SqList *&L, char &key)
{
	if (L->top == -1)
	{
		return;
	}
	key = L->data[L->top];
	L->top--;
}

void getTop(SqList *L,char &key)
{
	if (L->top == -1)
	{
		return;
	}
	key = L->data[L->top];
}



#关于下学期贫困生入库相关通知#

1、下学期要申请贫困生入库的同学，需回家在当地相关部门开好贫困证明
2、若学费为欠费状态的，需要办理生源地贷款，并把生源地贷款证明带回学校，方能入库

另，如果要办理生源地贷款，需要向银行提交学校收费证明，已上传群文件，请打印并盖章，带回家去
