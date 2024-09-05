#include <iostream>

using namespace std;
int power (int a,int n)
{
    int r=1;
    for (int i=1;i<=n;i++){
        r*=a;
    }
    return r;
}
int cal_End(int n, int a[])
{
    int s=0;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++)
            s+=a[i]*a[j];
    }
    return 2*s;
}
int num_digits (int a)
{
    int counter=0;
    while (a>0)
    {
        a/=10;
        counter++;
    }
    return counter;
}
void find_sharifi_nums(int End)
{
int counter=0,power_digits_sum=0;
    for (int i=100;i<=End;i++){
        int tmp=i;
        while (tmp>0){
            power_digits_sum+=power(tmp%10,num_digits(i));
            tmp/=10;
        }
        if(power_digits_sum==i){
        counter=1;
        cout<<i<<"\n";
        }
        power_digits_sum=0;
    }
    if (counter==0)
        cout<<"none";
}
int main()
{
int a[15],n,End;
cin>>n;
for (int i=0;i<n;i++)
    cin>>a[i];
End=cal_End(n,a);
find_sharifi_nums(End);
    return 0;
}
