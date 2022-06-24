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

int main()
{
   int t;cin>>t;
    while(t-->0){
        int n;cin>>n;
        vi arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,arr[i]+arr[i+1]);
        }
        cout<<maxi<<endl;
    }

}
