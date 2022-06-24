#include<bits/stdc++.h>
using namespace std;
#define ll long long
int vis[501][501];
int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
int k;
void func(vector<vector<char>>&arr,int r,int c){
    if(k<0)return;
    vis[r][c]=1;
    for(auto a:dir){
        int rd=r+a[0];int cd=c+a[1];
        if(rd>=0 && cd>=0 && rd<arr.size() && cd<arr[0].size() && vis[rd][cd]==0 && arr[rd][cd]!='#'){
            func(arr,rd,cd);
        }
    }
    if(k>0){
        arr[r][c]='X';
        k--;
    }
}
int main(){
    int n,m;cin>>n>>m>>k;
    vector<vector<char>>arr(n,vector<char>(m));
    int r,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='.'){
                r=i;c=j;
            }
        }
    }
    memset(vis,0,sizeof vis);
    func(arr,r,c);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}