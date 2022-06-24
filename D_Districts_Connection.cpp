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
void dfs(vi adj[],vi &vis,int ind){
    vis[ind]=1;
    for(int i:adj[ind]){
        if(vis[i])continue;
        dfs(adj,vis,i);
    }
}
int main(){
   
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
       set<int>s;
       map<int,int>m;
        for(int i=0;i<n;i++){
            cin>>b[i];
            s.insert(b[i]);
            m[b[i]]++;
        }
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            m[b[j]]--;
            if(m[b[j]]==0){
                s.erase(b[j]);
            }
            j++;
            auto x=s.lower_bound(a[i]);
            if(x!=s.end()&& *x==a[i]){
                ans+=m[a[i]];
            }

        }
        cout<<ans<<endl;
    }
}