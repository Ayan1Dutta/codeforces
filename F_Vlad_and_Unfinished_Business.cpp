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
vvi adj;
unordered_set<int> special;
vl special_cnt;
vl depth;
ll ans=0;
ll final_ans;
void dfs1(int u,int p){
    if(adj[u].size()==1){
        special_cnt[u]=(special.find(u)!=special.end()?1:0);
    }
    for(auto a:adj[u]){
        if(a==p)continue;
        depth[a]=depth[u]+1;
        dfs1(a,u);
        special_cnt[u]+=special_cnt[a]+(special.find(u)!=special.end()?1:0);
    }
}
void dfs2(int u,int p){
    for(auto x:adj[u]){
        if(x==p)continue;
        if(special_cnt[x]>0){
            ans+=2;
            dfs2(x,u);
        }
    }
}
void dfs3(int u,int p,ll dist=0){
    if(special.count(u)){
        final_ans=min(final_ans,ans-depth[u]+dist);
    }
    for(auto x:adj[u]){
        if(x==p)continue;
        dfs3(x,u,dist+1);
    }
}
int main(){
    int t;cin>>t;
    while (t--){
       int n,k,x,y;cin>>n>>k>>x>>y;
       ans=0;
        depth.assign(n+1,0);
        adj.assign(n+1,{});
        special_cnt.assign(n+1,0);
        special.clear();
       for(int i=0;i<k;i++){
           int u;cin>>u;
           special.insert(u);
       }
       for(int i=1;i<n;i++){
           int u,v;cin>>u>>v;
           adj[u].push_back(v);adj[v].push_back(u);
       }

        dfs1(x,-1);
        dfs2(x,-1);
        final_ans=1e18;
        dfs3(y,-1);
        cout<<final_ans<<endl;

    }
    return 0;
    
}