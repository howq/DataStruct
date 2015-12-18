#include <iostream>
#include <string>
using namespace std;
void swap(char &a, char &b){
	char temp = a;
	a = b;
	b = temp;
}

string bubSort(string a, int len){
	for (int i = 0; i < len; i++){
		for (int j = 1; j < len - i; j++){
			if (a[j - 1] > a[j]){
				swap(a[j - 1], a[j]);
			}
		}
	}
	return a;
}



bool judge(string word1, string word2){
	int len1 = word1.size(), len2 = word2.size();
	if (len1 != len2){
		return false;
	}
	else{
		word1 = bubSort(word1, len1);
		word2 = bubSort(word2, len2);
		if (word1.compare(word2) == 0){
			return true;
		}
		else
			return false;
	}
}

int main(){
	int time, i;
	string word1[50], word2[50];
	bool isSame[50];
	cin >> time;
	for (i = 0; i < time; i++){
		cin >> word1[i] >> word2[i];
		isSame[i] = judge(word1[i], word2[i]);
	}
	for (i = 0; i < time; i++){
		if (isSame[i])
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}