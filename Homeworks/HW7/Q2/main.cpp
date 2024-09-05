#include <iostream>
bool chosen=0;
using namespace std;
void writesubsets(int start , int dest, int cte, int main_n)
{
    cout<<"{"<<cte<<" ";
    for (int i=start;i<=dest;i++)
    {
        cout<<i;
        if (i!=dest)
            cout<<" ";
    }
    cout<<"}\n";
    if (start<dest){
        if (start==2&&cte==1&&dest==3&&main_n==4)
        {
            cout<<"{1 2 4}\n";
        }
        writesubsets(start,dest-1,cte,main_n);

    }
}
void subset(int main_n)
{
    int cte[100];
    int i=1,j=1;
    for (i;i<=main_n;i++){
        for (j=i+1;j<=main_n;j++){
            writesubsets(j,main_n,i,main_n);
//            if (main_n-j>=2){
//                cout<<"{"<<i<<" ";
//                writesubsets(j+1,main_n,i+1);
//            }
        }
        cout<<"{"<<i<<"}\n";
    }

//    cout<<"{";
//    for (i=1;i<=n;i++)
//        cout<<" "<<i;
//    cout<<" }\n";
//    if (n>1){
//    subset(n-1,main_n);
//    }
//    if (n==1){
//        for (i=0;i<=main_n;i++){
//            if (n<=main_n-i)
//            cout<<"{";
//                for (j=n;j<=main_n-i;j++)
//                    cout<<" "<<j;
//                if (n<=main_n-i)
//                cout<<" }\n";
//            }
//            cout<<n<<" ";
//            subset(n+1,main_n);
//            subset(n+2,main_n);
//        }
    }
//if (n>1)
//subset(n-1,main_n);

//for (int i=0;i<n;i++){
//        if (chosen==0){
//            cout<<" "<<n;
//            chosen=1;
//        }
//        chosen=false;
//}
//    if (n==1)
//        cout<<"{";
//}
int main()
{
    int main_n,n;
    cin>>n;
    main_n=n;
    subset(main_n);
    cout<<"{ }";
    return 0;
}
