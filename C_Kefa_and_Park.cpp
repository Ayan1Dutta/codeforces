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
vector<int> adj[100005];
int dfs(vector<int>&hascat,int k,int n,int p,int temp){
    if(temp>k) return 0;
    if(adj[n].size()==1 && adj[n][0]==p){
        if(temp<=k){
            return 1;
        } 
        else return 0;
    }
    int ans=0;
    for(auto a:adj[n]){
        
        if(a!=p){
           if(hascat[a]){
               ans+=dfs(hascat,k,a,n,temp+1);
               }
           else ans+=dfs(hascat,k,a,n,0);
        }
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> hascat(n+1);
    for(int i=1;i<=n;i++){
        cin>>hascat[i];
    }
     for(int i=1;i<n;i++){
         int a,b;cin>>a>>b;
         adj[a].push_back(b);
         adj[b].push_back(a);
    }
    int cat=hascat[1]==1?1:0;
    cout<<dfs(hascat,k,1,-1,cat)<<endl;
}