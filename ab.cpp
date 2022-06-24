#include <bits/stdc++.h>
using namespace std;
void print(int x)
{
    cerr << x;
    cerr << endl;
}
void print(long x)
{
    cerr << x;
    cerr << endl;
}
void print(long long x)
{
    cerr << x;
    cerr << endl;
}
void print(unsigned x)
{
    cerr << x;
    cerr << endl;
}
void print(unsigned long x)
{
    cerr << x;
    cerr << endl;
}
void print(unsigned long long x)
{
    cerr << x;
    cerr << endl;
}
void print(float x)
{
    cerr << x;
    cerr << endl;
}
void print(double x)
{
    cerr << x;
    cerr << endl;
}
void print(long double x)
{
    cerr << x;
    cerr << endl;
    cerr << endl;
}
void print(char x)
{
    cerr << '\'' << x << '\'';
    cerr << endl;
}
void print(const char *x)
{
    cerr << '\"' << x << '\"';
    cerr << endl;
}
void print(const string &x)
{
    cerr << '\"' << x << '\"';
    cerr << endl;
}
void print(bool x)
{
    cerr << (x ? "true" : "false");
    cerr << endl;
}
template <typename T>
void printList(std::initializer_list<T> text)
{
    for (auto &value : text)
        std::cout << value << " ";
}
template <typename T, typename V>
void print(std::pair<T, V> &x)
{
    cerr << '{';
    cerr << (x.first);
    cerr << ',';
    cerr << (x.second);
    cerr << '}';
    cerr << endl;
}
template <typename T>
void print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), cerr << (i);
    cerr << "}";
    cerr << endl;
}
#define int long long
#define range(i, n) for (int i = 0; i < n; i++)
#define range1(i, n) for (int i = 1; i <= n; i++)
#define mod9 1000000009
#define mod7 1000000007
#define INF 1e18
#define sp(y) fixed << setprecision(y)
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define test(x) \
    int x = 1;  \
    cin >> x;   \
    while (x--)
#define ff first
#define ss second
#define pii pair<int, int>
#define mii map<int, int>
#define mp make_pair
#define append push_back
#define pb pop_back
#define fast_io std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define input(x) cin >> (x)
/*
    The moment u realize u have nothing to lose,
    everything becomes easy....................
 
    --souvenger
 
*/
 
signed main()
{
    fast_io;
    test(x)
    {
        int n, k;
        cin >> n >> k;
        pair<int, int> a[n + 1];
        map<int, int> idx;
        int sum = 0;
        range(i, n)
        {
            int x;
            cin >> x;
            a[i] = {x - (n - i - 1), i};
            idx[x] = i;
            sum += x;
        }
        // sum-ai +(n-i-1)+k-1
        sort(a, a + n);
        for(int i=0;i<n;i++){
            cout<<a[i].first<<" ";
        }
        cout<<endl;
        // vector<pair<int, int>> vec;
        // int j = n - 1;
        //  range(i, k)
        //  {
        //      vec.push_back({a[j]., a[j].first});
        //      j--;
        //  }
        // sort(vec.begin(), vec.end());
        int i = n - 1;
        int m = k;
        while (m--)
        {
            // cout<<a[i].first<<endl;
            sum -= (a[i].first);
            i--;
            // sum += m;
            // m--;
        }
        sum -= (k) * (k - 1) / 2;
        cout << max(0ll, sum) << endl;
    }
    return 0;
}