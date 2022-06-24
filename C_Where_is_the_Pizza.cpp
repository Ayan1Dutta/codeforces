#include<bits/stdc++.h>
#define int                 long long int
#define ld                 long double
#define fps(x,y)           fixed << setprecision(y) << x
#define loop(i,a,n)        for(int i=a;i<=n;i++)
#define set_bits           __builtin_popcountll
#define sz(x)              ((int)(x).size())
#define rev(j,a,n)         for(int j=a;j>=n;j--)
#define it(i,v)            for(auto i=v.begin();i!=v.end();i++)
#define pb                 push_back
#define vi                 vector
#define all(v)             v.begin(),v.end()
#define pr                 pair<int, int>
#define ff                 first
#define ss                 second
#define ump                unordered_map
using namespace std;
 
 
const int mod=1000000007;
 
 
inline void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   #ifndef ONLINE_JUDGE
   freopen("inp.txt", "r", stdin);
   freopen("op.txt", "w", stdout);
   #endif
}
 
vi<bool> vis(500001);
vi<int> graph[500001];
set<int> c;
void dfs(int node,int &a,bool &poss){
    vis[node]= true;
    if(c.find(node)!= c.end()) poss= false;
    a++;
    for(auto child: graph[node]){
        if(!vis[child]){
            dfs(child,a,poss);
        }
    }
}
 
void test(){
    int n; cin>>n;
    vi<int> a(n);
    vi<int> b(n);
    loop(i,0,n-1) cin>>a[i];
    c.clear();
    loop(i,0,n-1){
        cin>>b[i];
        vis[i+1]=false;
        graph[i+1].clear();
    }
    loop(i,0,n-1){
        int x; cin>>x;
        c.insert(x);
        graph[a[i]].pb(b[i]);
        graph[b[i]].pb(a[i]);
    }
    int ans = 1;
    loop(i,1,n){
        if(!vis[i]){
            int a=0;
            bool poss= true;
            dfs(i,a,poss);
            if(poss && a>1)(ans *=2LL)%=mod;
        }
    }
 
    cout<<ans<<"\n";
 
 
}
 
 
int32_t main(){
    fastio();
    int tc=1;
    //prime();
    cin>>tc;
    while(tc--){
        test();
    }
 
 
    return 0;
}