#include<iostream>
using namespace std;

#define maxSize 50

typedef int DataType;

struct myList
{
	DataType list[maxSize];
	int size;
};

//初始化顺序表L
void ListInitiate(myList *L)
{
	L->size = 0;               //定义初始数据元素个数
}

//insert item
void ListInsert(myList *L, int key, DataType x)
{
	int j = L->size++;
	int i= 0;
	while (i < L->size - 1)
	{
		if (key==L->list[i])
		{
			while (j > i)
			{
				L->list[j] = L->list[j - 1];
				j--;
			}
			L->list[i] = x;
			return;
		}
		i++;
	}
	L->list[j] = x;
}

int main(){
	int m,x,key;
	myList fir;
	ListInitiate(&fir);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> fir.list[i];
	}
	fir.size = m;
	cin >> key >> x;
	ListInsert(&fir,key,x);

	for (m = 0; m < fir.size - 1; m++)
	{
		cout << fir.list[m] << " ";
	}
	cout << fir.list[m];
	return 0;
}