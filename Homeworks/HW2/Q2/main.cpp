#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
int w1,w2,w3,w4,w5;
double x1,x2,x3,x4,x5,GPA;
cin>>x1>>x2>>x3>>x4;
cin>>w1>>w2>>w3>>w4>>w5;
cin>>GPA;
x5=(GPA*(w1+w2+w3+w4+w5)-(x1*w1+x2*w2+x3*w3+x4*w4))/w5;
if((x5>0)&&(x5<=20))
cout<<fixed<<setprecision(1)<<x5;
else if(x5>20)
cout<<"Sorry! Ishala terme baad!";
else
cout<<"Afarin! Darskhoone ki boodi to?";
    return 0;
}
