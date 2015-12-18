#include <iostream>
using namespace std;

int main()
{
	int num, times, a[100], i = 0,sum = 0;
	cin >> num >> times;
	for (i = 0; i < times; i++)
	{
		cin >> a[i];
	}
	i = 0;
	while (i < times)
	{
		if (sum < num)
		{
			sum += a[i];
		} 
		else if (sum > num)
		{
			sum -= a[i-1];
		}
		else
		{
			break;
		}
		i++;
	}

	if (num == sum)
	{
		cout << "YES" << endl;
	} 
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}