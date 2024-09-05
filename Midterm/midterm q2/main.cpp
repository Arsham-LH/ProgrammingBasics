#include <iostream>

using namespace std;
long long int power(int a,int n)
{
long long int r=1;
for (long long int i=1;i<=n;i++)
{
    r*=a;
}
return r;
}
int main()
{
long long int m,n,k,m_,power=1,a;
cin>>m>>n>>k;
m_=m%k;
a=m_;
while (power<n)
{
  a*=m_;
  a%=k;
  power++;
}
cout<<a;
    return 0;
}
