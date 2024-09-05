#include <iostream>

using namespace std;
//long long int power(long long int a,long long int n)
//{
//long long int r=1;
//for (long long int i=1;i<=n;i++)
//{
//    r*=a;
//}
//return r;
//}

int main()
{
//long long int m,n,k,m_,power=1,result;
//cin>>m>>n>>k;
//m_=m%k;
//result=m_;
//while(power<n)
//{
//    while (result<k){
//    result*=m_;
//    power++;
//    }
//    result%=k;
//}
//cout<<result;
bool found=false;
int n,i,j;
long long int a[100][100],max_row[100],min_row[100],max_col[100],min_col[100];
cin>>n;
for (i=0;i<n;i++){
    for (j=0;j<n;j++)
{
    cin>>a[i][j];
}
}
for (i=0;i<n;i++){
    max_row[i]=a[i][0];
    min_row[i]=a[i][0];
for (j=0;j<n;j++){
    if (max_row[i]<a[i][j])
        max_row[i]=a[i][j];
    else if (min_row[i]>a[i][j])
        min_row[i]=a[i][j];
}
}
for (j=0;j<n;j++){
    max_col[j]=a[0][j];
    min_col[j]=a[0][j];
for (i=0;i<n;i++){
if (max_col[j]<a[i][j])
    max_col[j]=a[i][j];
else if (min_col[j]>a[i][j])
    min_col[j]=a[i][j];
}
}
for (i=0;i<n;i++)
{
    for (j=0;j<n;j++)
    {
        if (((a[i][j]==max_col[j])&&(a[i][j]==min_row[i]))||((a[i][j]==min_col[j])&&(a[i][j]==max_row[i]))){
            cout<<i<<" "<<j<<"\n";
            found=true;
        }

    }
}
if (found==false)
    cout<<"NO";








    return 0;
}
