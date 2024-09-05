#include <iostream>
using namespace std;
//double factor(int n){
//int i,c=1;
//for (i=1;i<=n;i++){
//    c*=i;
//}
//return c;
//}
int main()
{
int n,i,j;
cin>>n;
for(j=1;j<=n-1;j++)
cout<<" ";
cout<<"*\n";
for (i=2;i<=n-1;i++){
        for (j=1;j<=n-i;j++)
        cout<<" ";
    cout<<"*";
    for (int k=1;k<=n-2;k++)
        cout<<" ";
    cout<<"*";
    cout<<"\n";
}
for (int f=1;f<=n;f++){
    cout<<"* ";
}

//cout<<fixed<<setprecision(6)<<1.0/s;
    return 0;
}
