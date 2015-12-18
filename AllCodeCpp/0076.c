#include <stdio.h>
#include <string.h>
#define N 4000001
int hash[N];
int main()
{
	int i, n, y, a, max;
	scanf("%d", &n);
	max = 0;
	y = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (++hash[a] > max)
		{
			max = hash[a];
			y = a;
		}
		else if ((hash[a] == max) && (a <= y)){
			y = a;
		}
	}
	printf("%d\n", y);
	return 0;
}


/*

#include <stdio.h>
#define N 4000001
int hash[N];
int main()
{
	int i, n, y, a, max;
	for (i = 0; i < N; i++) hash[i] = 0;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &a);
		hash[a + 2000000]++;
	}
	max = 0;
	for (i = 0; i< N; i++)
	{
		if (hash[i] > max)
		{
			max = hash[i];
			y = i;
		}
	}
	printf("%d\n", y - 2000000);
	return 0;
}*/

/*
#include<iostream>
using namespace std;

int  mode(int *num, int size){
	int time[2000] = { 1 };
	int max = 0;
	int model;
	int i,j;
	for (i = 0; i < size; i++){
		for (j = i + 1; j < size; j++){
			if (num[i] = num[j]){
				time[i]++;
			}
		}
	}
	for (i = 0; i < size; i++){
		if (time[i] > max){
			max = time[i];
		}
	}
	for (i = 0; i < size; i++){
		if (time[i] == max){
			model = num[i];
		}
	}
	return model;
}

int main(){
	int i,size, model;
	int num[2000];
	cin >> size;
	for (i = 0; i < size; i++){
		cin >> num[i];
	}
	model = mode(num, size);
	cout << model << endl;
	return 0;
}

*/
