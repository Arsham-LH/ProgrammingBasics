#include <iostream>
#include<iomanip>
using namespace std;
struct student{
string name;
int stdnum;
double score;
};
int main()
{
int i=0,j=0;
student n[250];
string order,help1="",help2="";
getline(cin,order);
while(order!="scores")
{
    if(order=="add")
    {
        getline(cin,help1);
            if (i>=200){
                cout<<"class is full\n";
            }
            else{
                j=0;
                while (help1[j]<48||help1[j]>57)
                {
                    n[i].name+=help1[j];
                    j++;
                }
                n[i].name=(n[i].name).substr(0,j-1);
                while (help1[j]>=48&&help1[j]<=57)
                {
                    n[i].stdnum*=10;
                    n[i].stdnum+=help1[j]-48;
                    j++;
                }
                j++;
                while (help1[j]>=48&&help1[j]<=57&&j<help1.length())
                {
                    n[i].score*=10;
                    n[i].score+=help1[j]-48;
                    j++;
                }
                if (help1[j]=='.')
                {
                    j++;
                    double b=10.0;
                    while(help1[j]>=48&&help1[j]<=57&&j<help1.length()){
                    n[i].score+=(help1[j]-48)/b;
                    b*=10.0;
                    j++;
                    }
                }
                cout<<"added!\n";
                i++;
                help1="";
            }
    }
    else if (order=="withdraw")
    {
        bool found=false;
        getline(cin,help1);
        for (j=0;(j<i)&&(found==false);j++)
        {
            if (n[j].name==help1)
            {
                found=true;
                cout<<"deleted!\n";
                n[j].name="";
                n[j].stdnum=-1;
                n[j].score=-1;
            }
        }
            if (found==false)
                cout<<"name not found!\n";
        help1="";
    }
    else if (order=="edit")
    {
        getline(cin,help1);
        getline(cin,help2);
        bool found=false;
        for (j=0;(j<i)&&(found==false);j++)
        {
            if (n[j].name==help1)
            {
                found=true;
                n[j].name=help2;
                cout<<"edited!\n";
            }
        }
        if (found==false)
            cout<<"name not found!\n";
        help1="";
        help2="";
    }
    else if (order=="stdnum")
    {
        bool found=false;
        getline(cin,help1);
        for (j=0;(j<i)&&(found==false);j++)
        {
             if (n[j].name==help1)
             {
                 found=true;
                 cout<<n[j].stdnum<<"\n";
             }
        }
        if (found==false)
            cout<<"name not found!\n";
        help1="";
    }
    getline(cin,order);
}
for (j=0;(j<i);j++)
    if(n[j].name!="")
    cout<<n[j].name<<" "<<fixed<<setprecision(1)<<n[j].score<<"\n";
    return 0;
}
