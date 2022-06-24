#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t-->0){
        int x,y;
        cin>>x>>y;
        int c=x*x+y*y;
        int d=sqrt(c);
        
        if(x==0 && y==0)cout<<0<<endl;
        else if(d*d==c){
            cout<<1<<endl;
        }else{
            cout<<2<<endl;
        }
    }
}