#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
int i,n,a,ap,an,af,as,flag=0;
cin>>n;
cin>>af;
cin>>as;
ap=af;
a=as;
for(i=1;i<n-1;i++)
{
cin>>an;
if(((a-ap>0)&&(a-an>0))^((a-ap<0)&&(a-an<0)))
{
    flag=1;
    cout<<i<<"\t";
}
    ap=a;
    a=an;
}
if(flag==0)
    cout<<"Null";

    return 0;
}
