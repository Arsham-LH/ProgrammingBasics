#include <iostream>

using namespace std;

int main()
{
long long int n,num_digit=0;
cin>>n;
while (n>0)
{
    num_digit++;
    n/=10;
}
cout<<num_digit;
    return 0;
}
