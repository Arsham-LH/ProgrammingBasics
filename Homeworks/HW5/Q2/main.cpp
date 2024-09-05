#include <iostream>
using namespace std;
bool isprime(int a)//tashkhis aval boodn ya naboodn
{
    int flag=0;
    for (int i=2;(i<=a/2)&&(flag==0);i++)
    {
        if (a%i==0)
            flag=1;
    }
return flag==0;
}
double num_primes(int a)//teedad adade avale ghabl az a
{
double k=0;

    for (int i=2;i<a;i++)
        if (isprime(i)==true)
        k++;
    return k;
}
double num_divisors(int a)//tedade maghsum elayh haye a
{
    double k=0;
    for (int i=1;i<=a/2;i++)
        if (a%i==0)
        k++;
    return k+1;
}
double total_cost(double a[],int n)//vazn shokolat ha ro migire va gheymateshuno mide+jame kol
{
    double total_cost=0;
    double b[1000];
    for (int i=0;i<n;i++)
    {
        if (isprime(a[i])==1)
            b[i]=num_primes(a[i])/2.0;
        else
            b[i]=num_divisors(a[i]);
    }
    for (int i=0;i<n;i++)
        total_cost+=b[i];
    return total_cost;
}
double final_cost(double total_cost)//geymat baad az takhfif
{
int tmp=total_cost*10,sum_digits=0;
double final_cost;
while (tmp>0)
{
    sum_digits+=tmp%10;
    tmp/=10;
}
if (isprime(sum_digits)==1)
    final_cost=total_cost-num_primes(sum_digits);
else
    final_cost=total_cost-num_divisors(sum_digits);
return final_cost;
}
int main()
{
int n;
double a[1000],finalcost,totalcost;
cin>>n;
for (int i=0;i<n;i++)
    cin>>a[i];
totalcost=total_cost(a,n);
finalcost=final_cost(totalcost);
cout<<finalcost;
    return 0;
}
