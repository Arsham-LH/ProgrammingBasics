#include <iostream>

using namespace std;
bool isprime(int a)
{
    for (int i=2;i<=a/2;i++)
        if (a%i==0)
        return 0;
    return 1;
}
int main()
{
long long int n;
int j,i,tmp,flag=0;
cin>>n;
if (n%2==0)
{
    if (flag==1)
        cout<<" ";
    tmp=n;
    while (tmp%2==0)
    tmp/=2;
    cout<<2<<" ";
}
for (i=3;i<=n;i+=2)
{
    if (isprime(i)==1)
    {
        if (n%i==0)
        {
            if (flag==1)
            cout<<" ";
            j=i;
            while (tmp%j==0)
            {
                tmp/=j;
            }
            cout<<i;
            flag=1;
        }
    }
}

    return 0;
}
