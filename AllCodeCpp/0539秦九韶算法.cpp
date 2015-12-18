#include<iostream>
using namespace std;
int an[21];
int N;
int ji(int a,int x)
{
 if(x==0)
  return 1;
 else if(x==1)
  return a;
 else
  return a*ji(a,x-1);
}
int sum(int x)
{
 int endsum=0;
 int i;
 for(i=0;i<=N;i++)
 {
  endsum+=an[i]*ji(x,i);
 }
 return endsum;
}
int main()
{
    int x,i;
 cin>>N>>x;
 if(N<=20&&x<=10)
 {
 for(i=0;i<=N;i++)
  cin>>an[i];
 //printf("%d\n",sum(x));
 cout<<sum(x)<<endl;
 }
    return 0;
}