#include <iostream>

using namespace std;
struct person {
int age;
int history;
string name;
};
void swap_persons (person &a, person &b)
{
    person t;
    t.age=a.age;
    a.age=b.age;
    b.age=t.age;
    t.history=a.history;
    a.history=b.history;
    b.history=t.history;
    t.name=a.name;
    a.name=b.name;
    b.name=t.name;
}
void result (person a[],int n,int x)
{
    int i,j;
    if (x==1)
    {
        for (i=n-1;i>0;i--)
        {
            for (j=1;j<=i;j++)
            if (a[j].age>a[j-1].age)
            swap_persons(a[j],a[j-1]);
        }
    }
    else if (x==2)
    {
        for (i=n-1;i>0;i--)
        {
            for (j=1;j<=i;j++)
            if (a[j].history>a[j-1].history)
            swap_persons(a[j],a[j-1]);
        }
    }
for (i=0;i<n;i++)
    cout<<a[i].name<<" "<<a[i].age<<" "<<a[i].history<<"\n";
}
int main()
{
int n,i,x;
person a[1000];
cin>>n;
for (i=0;i<n;i++)
    cin>>a[i].name>>a[i].age>>a[i].history;
cin>>x;
result(a,n,x);
    return 0;
}
