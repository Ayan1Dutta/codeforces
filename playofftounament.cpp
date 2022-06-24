#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <istream>
#include <map>
#include <cmath>
#include <stack>
#include <set>
#include <cstring>
#include <string>
#include <fstream>
#define ll long long
#define maxn 200005
#define mdl 998244353
#define clr(a,n) for(int i=0;i<n;i++)a[i]=0
#define cfast std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define inc(i,a,n) for(int i=a;i<n;i++)
#define vset(a,n,m) for(ll i=0;i<n;i++)a[i]=m;
#define endl '\n'
using namespace std;
ll tree[1000005];
string s;
int n;
inline int mp(int n,int x) {
    return n + 1 - x;
}
void build(int o, int n) {
    if (o > n) {
        tree[o] = 1;
        return;
    }
    build(o * 2, n);
    build(o * 2 + 1, n);
    if (s[mp(n, o) - 1] == '?')tree[o] = tree[o * 2 + 1] + tree[o * 2];
    else if (s[mp(n, o) - 1] == '0')tree[o] = tree[o * 2+1];
    else tree[o] = tree[o * 2];
}
void rebuild(int o) {
    if (o == 0)return;
    if (s[mp(n, o) - 1] == '?')tree[o] = tree[o * 2 + 1] + tree[o * 2];
    else if (s[mp(n, o) - 1] == '0')tree[o] = tree[o * 2+1];
    else tree[o] = tree[o * 2];
    rebuild(o / 2);
}
int main() {
    cfast;
    int k;
    cin >> k;
    cin >> s;
    n = s.length();
    build(1, n);
    int q;
    cin >> q;
    while (q--) {
        int x;
        string c;
        cin >> x >> c;
        s[x - 1] = c[0];
        rebuild(mp(n, x));
     //   cout << "tree is:" << endl;
    //    inc(i, 1, n + 1)cout << tree[i] << " ";
        cout << tree[1] << endl;
    }
}