#include <iostream>
using namespace std;

#define maxSize 20

int main()
{
	int times,i,j;
	int num[maxSize][maxSize];
	while (true)
	{
		cin >> times;
		if (times==0)
		{
			break;
		}
		for (i = 0; i < times; i++)
		{
			for (j = 0; j < i + 1; j++)
			{
				if (j == 0 || j == i)
				{
					num[i][j] = 1;
				}
				else
				{
					num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
				}
				if (j==i)
				{
					cout << num[i][j] << endl;
				}
				else
				{
					cout << num[i][j] << " ";
				}
			}
		}
	}
	return 0;
}