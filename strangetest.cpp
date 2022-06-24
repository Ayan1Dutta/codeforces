
#include<bits/stdc++.h> 
typedef long long ll;
using namespace std;
const int mod = 1e9+7;
int n;
int a,b;
int main()
{ 
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        if(b<=a) cout<<a-b<<endl;//reundant 
        else{
            
            int res=b-a;
            for(int x=a;x<b;x++)
            {
                int t=0;
                for(int j=21;j>=0;j--)
                {
                    if(b>>j&1) t|=1<<j;
                    else if(x>>j&1) {
                        t|=1<<j;
                        break;
                    }
                }
                res=min(res,x-a+1+(x|t)-b);
            }
            cout<<res<<endl;
        }
    }
    return 0;
}