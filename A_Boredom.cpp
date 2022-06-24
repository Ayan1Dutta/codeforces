#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;cin>>n;
    vector<ll>arr(n);
    ll maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    vector<ll>frq(maxi+1,0);
    for(ll i:arr)frq[i]++;
    vector<ll>dp(maxi+1,0);
    dp[0]=0;dp[1]=1*frq[1];
    for(ll i=2;i<=maxi;i++){
        dp[i]=max(dp[i-1],dp[i-2]+frq[i]*i);
    }
    cout<<dp[maxi]<<endl;
    return 0;
}