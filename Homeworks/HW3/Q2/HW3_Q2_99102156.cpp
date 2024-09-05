#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
char c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,n1,n2,n3,n4,n5;
cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7>>c8>>c9>>c10;
c1-=48;
c2-=48;
c3-=48;
c4-=48;
c5-=48;
c6-=48;
c7-=48;
c8-=48;
c9-=48;
c10-=48;
n1=10*c1+c2;
n2=10*c3+c4;
n3=10*c5+c6;
n4=10*c7+c8;
n5=10*c9+c10;
cout<<(n1+n2+n3+n4+n5)/5;
    return 0;
}
