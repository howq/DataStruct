#include<iostream>
using namespace std;

bool change(bool changer){
	if (changer){
		return false;
	}
	else
		return true;
}

int main(){
	int n, time = 0,i,j;
	bool lock[100000] = { false };
	cin >> n;
	for (i = 0; i < n; i++){
		for (j = i; j < n; j += i + 1){
			lock[j] = change(lock[j]);
		}
	}
	i = 0;
	while (i < n){
		if (lock[i]){
			time++;
		}
		i++;
	}
	cout << time << endl;
	return 0;
}