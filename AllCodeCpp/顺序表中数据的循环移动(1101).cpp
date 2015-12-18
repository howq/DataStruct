#include<iostream>
using namespace std;

typedef int elemType;

#define MaxSize 512

typedef struct {
	elemType data[MaxSize];
	int lenth;
}LinkList;

void creat(LinkList *&L, elemType a[], int len)
{
	int i;
	L = new LinkList;
	for (i = 0; i < len; i++)
	{
		L->data[i] = a[i];
	}
	L->lenth = len;
}
void free(LinkList *&L)
{
	delete L;
}


void move(LinkList *L){}

/*
void move(LinkList *L)
{
	int i;
	elemType temp = L->data[0];
	for (i = 0; i < L->lenth-1; i++)
	{
		L->data[i] = L->data[i + 1];
	}
	L->data[i] = temp;
}*/

void show(LinkList *L)
{
	int i;
	for (i = 0; i < L->lenth-1; i++)
	{
		cout << L->data[i] << " ";
	}
	cout << L->data[i];
}

int main()
{
	int len,i,mover;
	elemType a[MaxSize];
	LinkList *m;
	cin >> len;
	for (i = 0; i < len; i++)
	{
		cin >> a[i];
	}
	cin >> mover;
	creat(m, a, len);
	mover %= m->lenth;
	for (i = 0; i < mover; i++)
	{
		move(m);
	}
	show(m);
	free(m);
	return 0;
}

/*
顺序表逆置与循环右移、左移
 
 （2）循环右移k位 
 void ConverseRight1(int A[],int n,int k)_ {  int T[MAX];   int i; 
  for(i=0;i<k;i++)  T[i]=A[n-k+i];   for(i=1;i<=n-k;i++)  A[n-i]=A[n-k-i];  for(i=0;i<k;i++)  A[k+i]=T[i];  
  } 
  void ConverseRight2(int A[],int n,int k) {  for(int j=0;j<k;j++)  {    int temp=A[n-1]; 
    for(int i=n-1;i>0;i--)      
	A[i]=A[i-1];   A[0]=temp; 
	 } 
	 } 
	 void ConverseRight3(int A[],int n,int k) {   ReverseSeg(A,0,n-k-1);  ReverseSeg(A,n-k,n-1);  ReverseSeg(A,0,n-1); } 
	 （3）循环左移k位 
	 void ConverseLeft1(int A[],int n,int k)_ {  int T[MAX];   int i; 
	  for(i=0;i<k;i++)  T[i]=A[i];   for(i=k;i<n;i++)  A[i-k]=A[i];  for(i=n-k;i<n;i++)  A[i]=T[i-k-n];  
	  } 
	  void ConverseLeft2(int A[],int n,int k) {   for(int j=0;j<k;j++)  {    int temp=A[0];   for(int i=1;i<n;i++)    
	  A[i-1]=A[i];   A[n-1]=temp;  } 
	  } 
	  注释：按段逆置函数 
	  void ReverseSeg(int A[],int from,int to) {   for(int i=0;i<(to-from+1)/2;i++)  {    int temp;   temp=A[from+i];   A[from+i]=A[to-i];   A[to-i]=temp; 
	   } 
	   } 
	   顺序表逆置与循环右移、左移——章进兴 0941901228 
	    
		void ConverseLeft3(int A[],int n,int k) {   ReverseSeg (A,0,k-1);  ReverseSeg (A,k,n-1);  ReverseSeg (A,0,n-1);  
		} 
*/