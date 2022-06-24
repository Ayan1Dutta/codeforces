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
struct DSU
{
    int n;
    vi p;
    DSU(int _n)
    {
        n = _n;
        p.assign(n + 1,0);
        for (int i = 1;i<=n;i++)p[i] = i;
    }
    int Find(int i)
    {
        if (p[i] == i)return i;
        return p[i] = Find(p[i]);
    }
    void Merge(int u,int v)
    {
        u = Find(u),v = Find(v);
        p[v] = u;
    }
};
int main()
{
    try
  {
    // setIO();
    int n;
    cin>>n;
    vvi list1,list2;//list2 stores the edges between pairs of nodes in different cc's
    DSU val(n);
    for (int i = 0;i<n - 1;i++){
        int u,v;
        cin>>u>>v;
        if (val.Find(u) == val.Find(v))
            list1.pb({u,v});
        else val.Merge(u,v);
    }   
    for (int u = 1;u<=n;u++){
        for (int v = u + 1;v<=n;v++){
            if (val.Find(u) == val.Find(v))continue;
            list2.pb({u,v});
            val.Merge(u,v);
        }
    }
 
    cout<<list2.size()<<'\n';
    for (int i = 0;i<(int)list2.size();i++)
        cout<<list1[i][0]<<" "<<list1[i][1]<<" "<<list2[i][0]<<" "<<list2[i][1]<<'\n';
    return 0;
  }
  catch (bad_alloc & ba)
  {
    return 0;
  }
}