#include <iostream>

using namespace std;
bool isprime(int x)
{
    if (x==1)
        return false;
    int i;
    for (i=2;i<=x/2;i++)
        if (x%i==0)
            return false;
    return true;
}
double print_mean(int n, int *a, int x)
{
    int number=0,i;
    double s=0;
    for (i=0;i<n;i++)
    {
        if (a[i]>x)
        {
            s+=a[i];
            number++;
        }
    }
    return s/number;
}
int find_nth_prime(int n)
{
    int i=2,j,x1=1,x2=1,x=2,num_prime=0;
    while (num_prime<n)
    {
        if (isprime(x)==true)
        {
            num_prime++;
        }
            x1=x2;
            x2=x;
            x=x1+x2;
            i++;
    }
    return i;
}
int divisors_sum(int x)
{
    int i,sum=0;
    for (i=1;i<=x/2;i++)
    {
        if (x%i==0)
            sum+=i;
    }
    sum+=x;
    return sum;
}
int num_divisors(int x)
{
    int i,n=0;
    for (i=2;i<=x/2;i++)
    {
        if (x%i==0&&isprime(i)==1)
            n++;
    }
    if (isprime(x)==1)
        n++;
    return n;
}
int max_prime_divisors(int n, int a[])
{
    int max_divisors=2,i;
    for (i=0;i<n;i++)
    {
        if (num_divisors(a[i])>max_divisors)
            max_divisors=num_divisors(a[i]);
    }
    if (n==1&&a[0]==1)
        return 1;
    return max_divisors;
}
long long int quick_num_divisors(long long int x)
{
    long long int i,tmp=x,pow_counter=0,num_divisors=1;
    for (i=1;tmp>1;i++)
    {
        while(tmp%i==0&&isprime(i)==1)
        {
            pow_counter++;
            tmp/=i;
        }
        num_divisors*=(pow_counter+1);
        pow_counter=0;
    }
    return num_divisors;
}
void bubblesort(int a[],int n)
{
    bool swapped=true;
    int i,j;
    for (i=0;i<n&&swapped==true;i++)
    {
        swapped=false;
        for (j=0;j<n-i-1;j++)
            if (a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swapped=true;
            }
    }
}
void reversebubblesort(int a[],int n)
{
    bool swapped=true;
    int i,j;
    for (i=0;i<n&&swapped==true;i++)
    {
        swapped=false;
        for (j=0;j<n-i-1;j++)
            if (a[j]<a[j+1]){
                swap(a[j],a[j+1]);
                swapped=true;
            }
    }
}
void recruits(string order)
{
    int i=0;
    bool changed=true;
    bool changed_i=true;
    bool changed_after_i=true;
    while(changed==true){
        changed=false;
        while(order[i+1]!=0)
        {
            if (changed_i==false)
                changed_after_i=false;
            changed_i=false;
            if (order[i]=='R'&&order[i+1]=='L')
            {
                changed=true;
                if(changed_i==false&&changed_after_i==false){
                order[i]='L';
                changed_i=true;
                order[i+1]='R';
                changed_after_i=true;
                }
            }
            i++;
        }
        cout<<order<<"\n";
        i=0;
    }
}
//void semi_sort(int a[],int &x,int &n)
//{
//  int i,mid=n%2==0?n/2-1:n/2,k=1;
//      for (j=0;j<)
//      for (i=0;i<n-1;i++)
//      {
//          if (a[i]>x){
//            swap(a[i],a[i+1]);
//          }
//      }
//}
void find_word(char ch[][],int n,string word)
{
    int i=0,j=0,k=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            while (word[k]!=0)
            {
                if (word[k]==a[i][j])
                    k++;
            }
        }
    }
}
int main()
{
int n,x,i=0,j=0;
char ch[100][100];
cin>>n;
for (i;i<n;i++)
{
    for(j;j<n;j++)
    {
        cin>>ch[i][j];
    }
}
string word;
getline(cin,word);
find_word(ch,n,word);
    return 0;
}








//cin>>n;
//for (i=0;i<n;i++)
//    cin>>score[i]>>ranking[i];
//bubblesort(score,n);
//reversebubblesort(ranking,n);
//for (i=0;i<n;i++){
//    cout<<score[i]<<" : "<<ranking[i]<<"\n";
//}
