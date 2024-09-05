#include <iostream>
#include<iomanip>
using namespace std;
double power(double a,int f){
    double result=a;
for (int i=1;i<f;i++)
    result*=a;
    return result;
}
double amount(double d){
if (d>0)
    return d;
else
        return -d;
}
double root(double a,int n){
double x=0.000;
while (power(x,n)<=a){
    x+=1;
}
x-=2;
while (power(x,n)<=a){
    x+=0.1;
}
x-=0.2;
while (power(x,n)<=a){
    x+=0.01;
}
x-=0.02;
while (power(x,n)<=a){
    x+=0.001;
}
x-=0.002;
while (power(x,n)<=a){
    x+=0.0001;
}
x-=0.0002;
while (power(x,n)<=a){
    x+=0.00001;
}
x-=0.00002;
return x;
}
int main()
{
int n;
double a;
cin>>a>>n;
double x=root(a,n);
if (n%2==0)
cout<<fixed<<setprecision(2)<<x-0.004<<"\n"<<-x+0.004;
else
cout<<fixed<<setprecision(2)<<x-0.004;
if (n==3){
        cout<<"\n";
    double notreal1_1=-root(a,3)/2;
    double notreal1_2=(root(3,2)*amount(root(a,3))/2);
    double notreal2_1=-root(a,3)/2;
    double notreal2_2=-(root(3,2)*amount(root(a,3))/2);
cout<<fixed<<setprecision(2)<<notreal1_1+0.004<<"+"<<fixed<<setprecision(2)<<notreal1_2-0.004<<"i";
cout<<"\n"<<fixed<<setprecision(2)<<notreal2_1+0.004<<fixed<<setprecision(2)<<notreal2_2+0.004<<"i";
}
    return 0;
}
