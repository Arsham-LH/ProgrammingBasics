#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
int n,d1,d2;
cin>>n;
d1=n/10000;
d2=n%10;
if (d1!=d2)
    cout<<"no";
else {
    n%=10000;
    n/=10;
    d1=n/100;
    d2=n%10;
    if (d1!=d2)
        cout<<"no";
    else
        cout<<"yes";

}
    return 0;
}
