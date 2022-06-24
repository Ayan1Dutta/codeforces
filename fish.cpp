
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
double a[20][20],dp[1<<18];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) scanf("%lf",&a[i][j]);
	dp[(1<<n)-1]=1;
	for(int S=(1<<n)-2;S>=1;S--)
	{
		int num=0,SS=S;
		while(SS) num+=(SS&1),SS>>=1;
		for(int i=1;i<=n;i++) if(!(S&(1<<(i-1))))
			for(int j=1;j<=n;j++) if(S&(1<<(j-1)))
				dp[S]+=dp[S|(1<<(i-1))]*a[j][i]*2/(num+1)/num;
	}
	for(int i=1;i<=n;i++) printf("%lf ",dp[1<<(i-1)]);
	puts("");
	return 0;
}