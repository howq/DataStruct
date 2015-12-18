#include<iostream>
using namespace std;

#define maxSize 50

struct myList
{
	int list[maxSize];
	int size;
};

//初始化顺序表L
void ListInitiate(myList *L)
{
	L->size = 0;               //定义初始数据元素个数
}

//逆置
int ListReverse(myList *L)
{
	int i, m = L->size / 2, n = L->size;
	int tmp;

	for (i = 0; i < m; i++)
	{
		tmp = L->list[i];
		L->list[i] = L->list[n - 1 - i];
		L->list[n - 1 - i] = tmp;
	}
}
//合并
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
}

int main(){
	int m, n;
	myList fir, sec, third;
	ListInitiate(&fir);
	ListInitiate(&sec);
	ListInitiate(&third);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> fir.list[i];
	}
	fir.size = m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sec.list[i];
	}
	sec.size = n;
	ListMerger(&fir, &sec, &third);
	for (m = 0; m < third.size-1; m++)
	{
		cout << third.list[m] << " ";
	}
	cout << third.list[m];
	return 0;
}