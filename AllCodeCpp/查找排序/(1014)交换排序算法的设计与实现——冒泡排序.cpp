#include<iostream>
using namespace std;

void BubbleSort(int datas[], int len)
{
	int i, j;
	//for (i = 0; i < len; i++)
	for (i = 0; i < 1; i++)
	{
		for (j = 1; j < len - i; j++)
		{
			if (datas[j - 1]>datas[j])
			{
				int temp = datas[j - 1];
				datas[j - 1] = datas[j];
				datas[j] = temp;
			}
		}
	}
	for (i = 0; i < len; i++)
	{
		cout << datas[i]<<" ";
	}
}

int main()
{
	int datas[512];
	int len,i;
	cin >> len;
	for (i = 0; i < len; i++)
	{
		cin >> datas[i];
	}
	BubbleSort(datas, len);
	return 0;
}