#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vc vector
#define imax INT_MAX
#define imin INT_MIN
#define ff first
#define ss second
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define cu continue
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll mod = 1e9 + 7;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/*----------------------------------------------------------------------------------------------------------------------------*/
 
void read(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
 
const int maxN = 2 * (1e5 + 5);
vl g[maxN] , dp(maxN , 0) , lev(maxN , 0);
 
void dfs(int node , int par , int curr_level){
    lev[node] = curr_level;
    int cnt = 0;
 
    for(auto it : g[node]){
        if(it == par)
            cu;
        dfs(it , node , curr_level + 1);
        // subtree size calculating
        cnt += dp[it];
    }
    dp[node] += cnt + 1;
 
}
 
int main()
{
   // read();
    int t = 1;
    while(t--){
        ll n , k , x , y;
        cin >> n >> k;
        for(int i = 0 ; i < n - 1 ; i++){
            cin >> x >> y;
            g[x].pb(y); g[y].pb(x);
        }
        dfs(1 , -1 , 0);
        vl v;
        for(int i = 1 ; i <= n ; i++){
            v.pb(lev[i] - (dp[i] - 1));
        }
 
        sort(rall(v));
 
        ll ans = 0;
        for(int i = 0 ; i < k ; i++){
            ans += v[i];
        }
 
        cout<<ans<<endl;
 
    }
    
    return 0;
}