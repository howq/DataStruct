#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
  
int Hash[100];
int main()
{
    int len, n;
    cin >> len >> n;
    memset(Hash, -1, sizeof(Hash));
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int j = x % 13;
        while (Hash[j] != -1)
        {
            j = (j + 1) % 13;
        }
        Hash[j] = x;
    }
    int x;
    cin >> x;
    int ans = 1;
    int j = x % 13;
    while (Hash[j] != x && ans <= len)
    {
        ans++;
        j = (j + 1) % 13;
    }
    if (ans <= 13)
        cout << j << "," << ans;
    else
        cout << -1;
}