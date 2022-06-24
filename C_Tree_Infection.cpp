#include<bits/stdc++.h>
using namespace std;
//1 child 0 direct inject
void func(vector<vector<int>>& a,vector<int>&out,vector<int>&sor){
    int i=0;int day=1;
    queue<pair<int,int>>q;
    q.push({sor[i],1});
    a[sor[i]].pop_back();
    while(!q.empty()){
        int n=q.size();
        while(n-->0){
            auto a=q.front();
            
        }
    }
}
int main(){
    int t;cin>>t;
    while(t-->0){
        int n;cin>>n;
        vector<vector<int>> adj(n+1);
        vector<int> out(n+1);
        for(int i=2;i<=n;i++){
            int v;cin>>v;
            adj[v].push_back(i);
            out[v]++;
        }
        vector<int> ass(n);
        for(int i=1;i<=n;i++) ass[i]=i;
        sort(ass.begin(),ass.end(),[&](auto a,auto b){
            return out[a]>=out[b];
        });
        func(adj,out,ass);
    }
    
    return 0;
}