#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
double a,b,c,d;
cin>>a>>b>>c;
d=b*b-4*a*c+0;
if (a==0&&b==0)
    cout<<"there is no answer.";
else if (a==0&&b!=0)
    cout<<fixed<<setprecision(6)<<-c/b+0;
else if (a!=0){
    if (d>0){
        cout<<fixed<<setprecision(6)<<(-b+sqrt(d))/(2*a)+0<<"\n";
        cout<<fixed<<setprecision(6)<<(-b-sqrt(d))/(2*a)+0;
    }
    else if (d==0){
        cout<<fixed<<setprecision(6)<<-b/(2*a)+0;
    }
    else
        cout<<"there is no answer.";

}
    return 0;
}
