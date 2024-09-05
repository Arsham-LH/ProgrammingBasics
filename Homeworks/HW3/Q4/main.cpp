#include <iostream>
#include<cmath>
using namespace std;

int main()
{
int n1,n2,n3,s;
cin>>n1>>n2>>n3;
while ((n1<1||n1>24)||(n2>30||n2<1)||(n3<8||n3>12)||(n2>29&&n3==12)||(n3<8)||(n3==8&&n2<9)||(n3==8&&n2==9&&n1<14)){
    cout<<"please enter inputs again.";
    cin>>n1>>n2>>n3;
}
if (n3!=8)
s=n1*3600+n2*24*3600+(n3-9)*30*24*3600+20*24*3600+10*3600;
else
s=n1*3600+(n2-10)*24*3600+10*3600;
cout<<s<<" sec";




    return 0;
}
