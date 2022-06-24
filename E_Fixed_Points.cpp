#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
void func(vi& arr,int k){
    int n=arr.size()-1;
    vvi dp(n+1,vi(n+1));
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+(arr[i]==i?1:0);
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1];
            dp[i][j]=max(dp[i][j],dp[i-1][j]+(arr[i]==(i-j)?1:0));
        }
    }
    bool is = false;
        for (int j = 0;j<=n;j++){
            if (dp[n][j] >= k){cout<<j<<endl;is = true;break;}
        }
        
        if (!is)cout<<-1<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vi v(n+1);
        for(int i=1;i<=n;i++)cin>>v[i];
        func(v,k);
    }
}