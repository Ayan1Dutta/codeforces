#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define vp vector<pp>
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
const int M=1000000007;
int dx [8] = {-2,-1,1,2,2,1,-1,-2};
int dy [8] = {1,2,2,1,-1,-2,-2,-1};
ll pow(ll x, ll n, ll d) {
		if(n == 0 ) return 1 % d;
		if(x < 0) return pow(x + d, n , d);
		if(n == 1) return x % d;
		ll ans = 1;
		while(n > 0 ){
			if(n % 2 == 0){
				x = x * x % d;
				n = n /2;
			}else {
				ans  = (ans * x) % d;
				n = n -1;
			}
		}
		return ans % d;
	}
int main(){
  int t=1;
  cin>>t;
    while (t--){
        ll n , k ;
		cin>>n>>k;
	
  
        ll ans = (pow(2,n-1,M) * k) % M;
  

		cout<<ans<<endl;
	}
		
}


