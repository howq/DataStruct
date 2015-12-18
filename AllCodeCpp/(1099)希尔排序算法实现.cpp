#include <iostream>

using namespace std;

int a[512];

void shell_sort(int unsorted[], int len)
{
	int group, i, j, temp;
	int once = len / 2 - 1;
//	for (group = len / 2; group > 0; group /= 2)
	for (group = len / 2; group > once; group /= 2)
	{
		for (i = group; i < len; i++)
		{
			for (j = i - group; j >= 0; j -= group)
			{
				if (unsorted[j] > unsorted[j + group])
				{
					temp = unsorted[j];
					unsorted[j] = unsorted[j + group];
					unsorted[j + group] = temp;
				}
			}
		}
	}
}

/*
void shell_sort(int a[], int n)
{
	int gap;
	for (gap = 3; gap > 0; gap--)
	{
		for (int i = 0; i < gap; i++)
		{
			for (int j = i + gap; j < n; j = j + gap)
			{
				if (a[j]<a[j - gap])
				{
					int temp = a[j];
					int k = j - gap;
					while (k >= 0 && a[k]>temp)
					{
						a[k + gap] = a[k];
						k = k - gap;
					}
					a[k + gap] = temp;
				}
			}
		}
	}
}*/

int main()
{
	int len;
	cin >> len;
	for (int i = 0; i < len; i++)
		cin >> a[i];
	shell_sort(a, len);
	for (int i = 0; i<len; i++)
		cout << a[i] << " ";
	return 0;
}

