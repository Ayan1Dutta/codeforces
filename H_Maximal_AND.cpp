#include<bits/stdc++.h> 
typedef string str;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef priority_queue<int> pqi;
typedef vector<ll> vll;
typedef vector<str> vs;
typedef vector<char> vc;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef map<ll, ll> mpll;
typedef set<ll> si;
#define f(i, a, n) for (ll i = a; i < n; i++)
#define f2(i, a, b) for (ll i = a; i <= b; i++)
#define f3(i, n, m) for (ll i = n; i >= m; i--)
using namespace std;
void disp(vll v)
{
  for (auto u : v)
    cout << u << " ";
  cout << endl;
}
void solve()
{
  ll n, k,ans=0;
  cin >> n >> k;
  vll a(n);
  f(i, 0, n) cin >> a[i];
  vll cnt(32, 0),pos;
  f(i, 0, n)
  {
    bitset<32> x(a[i]);
    f(j, 0, 32)
    {
      cnt[j] += x[j];
    }
  }
  f3(i,31,0)
  {
    if(i==31)
    {
      if(cnt[i]==n) pos.pb(i);
    }
    else 
    {
      if(k>=(n-cnt[i])) 
      {
        k-=(n-cnt[i]);
        pos.pb(i);
      }
    }
  }
  f(i,0,sz(pos))
  {
    ans+=(1<<pos[i]);
  }
  cout<<ans<<endl;
}
 
int main()
{
  fast_cin();
  w(t1)
  solve();
 
  return 0;
}