#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n;
int a[MAXN];
int BIT[MAXN];
void update(int i,int val){
	for(;i<=n;i+= i&-i)
		BIT[i]+=val;
}
long long query(int i){
	long long sum=0;
	for(;i>0;i-= i&-i)
		sum+=BIT[i];
	return sum;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(a[i]+1,1);
	}
	int m;
	cin>>m;
	while(m--){
	 	int j;
	 	cin>>j;
	 	cout<<query(a[j]+1);
	}
	return 0;
}