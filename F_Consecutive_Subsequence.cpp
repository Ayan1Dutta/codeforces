#include<bits/stdc++.h>
using namespace std;
template<typename G>inline void read(G&x) {x=0;G f=1;char ch=getchar();while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();if(ch=='-') {f=-1;ch=getchar();}while(ch>='0'&&ch<='9') {x=x*10+(ch^48);ch=getchar();}x*=f;}
const int MAXN=1000,MAXM=1000;
int n,m,k;
struct node{
    int l,r,d,w;
    bool operator<(const node &x)const{
        if(w==x.w) return d<x.d;
        return w<x.w;
    }
}a[MAXN];
bool cmp(node A,node B) {
	return A.l<B.l;
}
priority_queue<node> q;
int w[MAXN],c[MAXN];
long long dp[MAXN][MAXM];
int main() {
	memset(dp,0x3f,sizeof(dp));c[0]=1;
	read(n),read(m),read(k);
	for(int i=1;i<=k;++i) {
		read(a[i].l),read(a[i].r),read(a[i].d),read(a[i].w);
	}
	sort(a+1,a+1+k,cmp);
	int l=1;
	for(int i=1;i<=n;++i) {
		while(a[l].l<=i&&l<=k) {
			q.push(a[l]);
			++l;
		} 
		c[i]=i+1;
		while(!q.empty()) {
			node tmp=q.top();
			q.pop();
			if(tmp.r<i) continue;
			c[i]=tmp.d+1,w[i]=tmp.w;
			q.push(tmp);
			break;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<=n;++i) {
		for(int j=0;j<=m;++j) {
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
			dp[c[i]][j]=min(dp[c[i]][j],dp[i][j]+w[i]);
		} 
	}
    for(int i=0;i<=n;++i) {
		for(int j=0;j<=m;++j) {
			cout<<dp[i][j]<<" ";
		}
        cout<<endl;
	}
	long long ans=LONG_LONG_MAX;
	for(int i=0;i<=m;++i) ans=min(ans,dp[n+1][i]);
	printf("%lld",ans);
	return 0;
}