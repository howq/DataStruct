#include<iostream>
using namespace std;

void MinheapsortTodescendarray(int a[], int n)
{
	for (int i = n - 1; i >= 1; i--)
	{
		Swap(a[i], a[0]);
		MinHeapFixdown(a, 0, i);
	}
}
int main()
{
	int datas[512];
	int len, i;
	cin >> len;
	for (i = 0; i < len; i++)
	{
		cin >> datas[i];
	}
	BubbleSort(datas, len);
	return 0;
}