#include<stdio.h>
#include<stdlib.h>
void judge(int *, int);
int main()
{
	int num;
	scanf_s("%d", &num);
	int a[100];
	int i;
	for (i = 1; i <= num; i++)
	{
		scanf_s("%d", a + i);
	}
	judge(a, num);
	return 0;
}
void judge(int *a, int n)
{
	int i;
	for (i = 1; i <= n / 2; i++)
	{
		if (a[i] < a[i * 2] || a[i] < a[2 * i + 1])
		{
			printf_s("Yes"); return;
		}
	}
	printf_s("No");
}