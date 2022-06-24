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
using vp=vector<pair<ll,ll>>;
using vvc = vector<vc>;
using vs = vector<string>;
#define ff first
#define ss second
vector<int>adj[200007];
const int mod=1000000007;
bool helper(vvi grid,int i, int j, int sum,vector<vector<unordered_map<int,bool>>>dp) {
		
		if(i == grid.size() -1 && j == grid[0].size() -1) {
			if(sum + grid[i][j] == 0) return true;
			return false;
		}
		
		if(i >= grid.size() || j >= grid[0].size()) return false;
		if(dp[i][j][sum]) return dp[i][j][sum];
		
		if(helper(grid,i+1,j,sum + grid[i][j],dp)) {
			dp[i][j][sum]=1;
			return true;
		}
		else if(helper(grid,i,j+1,sum + grid[i][j],dp)) {
			dp[i][j][sum]=1;
			return true;
		}
		else {
			dp[i][j][sum]=0;
			return false;
		}
		
	}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vvi grid(n,vi(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        vector<vector<unordered_map<int,bool>>>dp(n,vector<unordered_map<int,bool>>(m));
			 for(int i = 0 ; i < n; i++) {
					for(int j = 0 ; j < m ; j++) {
						dp[i][j].clear();
					}
				}
        if(helper(grid,0,0,0,dp)){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}