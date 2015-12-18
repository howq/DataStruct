#include<iostream>
#include<stdio.h>
using namespace std;

int binSeek(int *data, int key, int first, int last,int &time){	
	int mid;
	time = 0;
	last = last - 1;
	if (first > last){
		return -1;
	}
	while (first <= last){
		mid = (first + last) / 2;
		time++;
		if (data[mid] == key){
			return mid;
		}
		else if (data[mid] >= key){
			last = mid - 1;
		}
		else{
			first = mid + 1;
		}
	}
	return -1;
}

int main(){
	int num[90],size, i, result, key,time;
	cin >> size;
	for (i = 0; i < size; i++){
		cin >> num[i];
	}
	cin >> key;
	result = binSeek(num, key, 0, size,time);
	cout << result <<"\r\n"<< time;
	return 0;
}

/*
#include<iostream>
using namespace std;
int a[1000];
void search(int left, int m, int right)
{
	int mid;
	int temp = 0;
	while (left <= right)
	{
		mid = (right + left) / 2;
		temp++;
		if (a[mid] == m)
		{
			cout << mid << "\r\n" << temp;
			return;
		}
		else if (a[mid] > m)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << "-1" << "\r\n" << temp;
}

int main(){
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	search(0, m, n - 1);
	return 0;
}*/