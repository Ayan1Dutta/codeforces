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
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int dp[501][501];
int helper(vector<int>&ind,vector<int>&speed,int k,int index){
    int n=ind.size();
    if(index==n-1) return 0;
    if(dp[index][k]!=-1) return dp[index][k];
    int ans=INT_MAX;
    for(int i=index+1;i<n;i++){
        if(i-index-1>k) break;
        ans=min(ans,speed[index]*(ind[i]-ind[index])+helper(ind,speed,k-(i-index)+1,i));
    }
    return dp[index][k]=ans;
}
int main(){
    // setIO();
    int n,l,k;
    cin>>n>>l>>k;
    vector<int> ind(n),speed(n);
    for(int i=0;i<n;i++){
        cin>>ind[i];
    }
    ind.push_back(l);
    for(int i=0;i<n;i++){
        cin>>speed[i];
    }
    speed.push_back(0);
    memset(dp,-1,sizeof(dp));
    int a=helper(ind,speed,k,0);
    cout<<a<<endl;
    return 0;
}