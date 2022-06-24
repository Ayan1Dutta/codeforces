#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
lli dp[50001][501] , k , result;
vi ar[50001];
 
void dfs(int node , int par)
{
	dp[node][0] = 1;
 
	for(int child : ar[node])
	if(child != par)
	{
		dfs(child , node);

		for(int i=0;i<=k;i++)
		{
			result += dp[node][i] * dp[child][k-1-i];
			dp[node][i] += dp[child][i-1];
		}
	}
 
	// for(int i=k;i>=0;i--) dp[node][i] = dp[node][i-1];
	// dp[node][0] = 0;
}
 
int main()
{
	int n , a , b;
	cin>>n>>k;
 
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
 
	dfs(1 , 0);
 
	cout<<result;
}