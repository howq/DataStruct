#include<iostream>
using namespace std;

int gcd(int m, int n){
	if (m < n){
		int temp = m;
		m = n;
		n = temp;
	}
	if (m%n == 0){
		return n;
	}
	else{
		gcd(n, m%n);
	}
}

int minMul(int m, int n, int maxGcd){
	return m*n / maxGcd;
}

int main(){
	int m, n;
	int maxGc, minMu;
	cin >> m >> n;
	maxGc = gcd(m, n);
	minMu = minMul(m, n, maxGc);
	cout << maxGc <<" "<< minMu << endl;
	return 0;
}