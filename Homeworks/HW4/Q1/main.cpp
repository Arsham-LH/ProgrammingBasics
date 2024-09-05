#include <iostream>

using namespace std;

int main()
{
int n,i,j,k=1;
cin>>n;
for (i=1;i<=n;i++){
    for (j=1;j<=n;j++){
        cout<<k*j<<" ";
    }
    k++;
    cout<<"\n";
}
    return 0;
}
