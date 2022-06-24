#include<bits/stdc++.h> 
typedef long long ll;
using namespace std;
#define DIVYA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<=b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define sz(x) (ll)x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cin >> n;
		vll cnt(n + 1, 0);
		multiset<ll>st;
		for(int i=1;i<=n;i++)
		{
			ll x;
			cin >> x;
			st.insert(x);
			cnt[x]++;
		}
		vll ans(n + 1, 0);
		ans[0] = cnt[0];
		for(int i=1;i<=n;i++)
		{
			ans[i] = ans[i - 1] - cnt[i - 1];
			auto it = st.ub(i - 1);
			if (it == st.begin())
			{
				for(int j=i;j<=n;j++)ans[j] = -1;
				break;
			}
			it--;
			ans[i] += i - 1 - *it;
			ans[i] += cnt[i];
			st.erase(it);
		}
		for(int i=0;i<=n;i++)cout << ans[i] << " ";
		cout << "\n";
    }
}