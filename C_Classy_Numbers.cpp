#include <bits/stdc++.h>
using namespace std;
 
/* macros */
#define inf 1e9
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vt vector
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define gtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": " << solve() << "\n";TC++;}
#define gvtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": "; vsolve(); TC++;}
#define notc solve();
#define mod 1000000007
#define ret return 0;
string s;
int dp[20][4][2];
 
int go (int pos, int cnt, int tight) {
    if (pos == s.size()) {
        return 1;
    }
 
    int &ans = dp[pos][cnt][tight];
    
    if (ans != -1) {
        return ans;
    }
    
    int en = (tight == 1) ? s[pos] - '0' : 9;
    ans = 0;
    for (int i=0;i<=en;i++) {
        if (cnt + (i > 0) <= 3) {
            ans += go (pos + 1, cnt + (i > 0), tight & (i == en));
        }
    }
    
    return ans;
    
}
 
 
void solve() {
    int l,r;
    cin>>l>>r;
 
    s = to_string(r);
    memset(dp, -1, sizeof dp);
    int ans = go (0,0,1);
    l -= 1;
    s = to_string(l);
    memset(dp, -1, sizeof dp);
    ans -= go (0,0,1);
    cout << ans << "\n";
}
 
int32_t main(){
    fastio
    tc
    ret
}