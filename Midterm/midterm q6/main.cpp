#include <iostream>

using namespace std;

int main()
{
string x;
long long int sum,i,counter=0,tmp,m,a[1000];
getline(cin,x);
m=x.length();
for (i=0;i<m;i++){
sum+=x[i]-'0';
}
counter++;
while (sum>10){
counter++;
tmp=sum;
m=1;
while (tmp>10)
{
    tmp/=10;
    m+=1;
}
tmp=sum;
for (int j=m-1;j>=0;j--){
    a[j]=tmp%10;
    tmp/=10;
}
sum=0;
for (int j=0;j<m;j++)
    sum+=a[j];
}
cout<<counter;
    return 0;
}
