#include<iostream>
using namespace std;

void Insertsort(int a[], int n)
{
	int i, j;
//	for (i = 1; i < n; i++)
	for (i = 1; i < 2; i++)
	{
		for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
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
	Insertsort(datas, len);
	return 0;
}