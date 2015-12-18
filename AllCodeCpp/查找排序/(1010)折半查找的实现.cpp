#include<iostream>
using namespace std;

int binFind(int *data, int key, int left, int right, int &times)
{
	int mid;
	if (left > right)
		return -1;
	while (left <= right)
	{
		times++;
		mid = (left + right) / 2;
		if (data[mid] == key)
		{
			return mid;
		}
		else if (data[mid] >= key)
		{
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return -1;
}

int main()
{
	int data[100];
	int longChar, key, i, times = 0, result;
	cin >> longChar;
	for (i = 0; i < longChar; i++)
	{
		cin >> data[i];
	}
	cin >> key;
	result = binFind(data, key, 0, longChar, times);
	cout << result << "\n" << times;
	return 0;
}


/*
#include <iostream>
using namespace std;

int binSearch(int a[], int key, int left, int right, int &times)
{
	if (left > right)
	{
		return -1;
	}
	times++;
	int mid = (left + right) / 2;
	if (a[mid] == key)
	{
		return mid;
	}
	else if (a[mid] > key)
	{
		binSearch(a, key, left, mid - 1, times);
	}
	else
	{
		binSearch(a, key, mid + 1, right, times);
	}
}

int main()
{
	int datas[512];
	int times = 0, key, lenth, i, result;
	cin >> lenth;
	for (i = 0; i < lenth; i++)
		cin >> datas[i];
	cin >> key;
	result = binSearch(datas, key, 0, lenth - 1, times);
	cout << result << "\n" << times;
	return 0;
}*/

