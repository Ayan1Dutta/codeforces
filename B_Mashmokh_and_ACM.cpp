#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
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
const int mod=1e9+7;
const int N=100004;
int bit[N];
void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vi a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        
    }
    return 0;
}