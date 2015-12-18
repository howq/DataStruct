#include<iostream>
using namespace std;

#define maxSize 50

typedef char DataType;

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

//逆置
void ListReverse(myList *L)
{
	int i, m = L->size / 2, n = L->size;
	DataType tmp;

	for (i = 0; i < m; i++)
	{
		tmp = L->list[i];
		L->list[i] = L->list[n - 1 - i];
		L->list[n - 1 - i] = tmp;
	}
}
//合并
/*
void  ListMerger(myList *La, myList *Lb, myList *Lc)
{
	int i = 0, j = 0, k = 0;
	while (i < La->size&&j < Lb->size)
	{
		if (La->list[i] < Lb->list[j])
		{
			Lc->list[k] = La->list[i];
			i++;
			k++;
		}

		else
		{
			Lc->list[k] = Lb->list[j];
			j++;
			k++;
		}
	}
	while (i < La->size)
	{
		Lc->list[k++] = La->list[i++];
	}



	while (j < Lb->size)
	{
		Lc->list[k++] = Lb->list[j++];
	}
	Lc->size = k;
}*/

int main(){
	int m;
	myList fir;
	ListInitiate(&fir);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> fir.list[i];
	}
	fir.size = m;
	ListReverse(&fir);
	for (m = 0; m < fir.size - 1; m++)
	{
		cout << fir.list[m] << " ";
	}
	cout << fir.list[m];
	return 0;
}