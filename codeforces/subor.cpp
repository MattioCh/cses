#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <unordered_map>
#include <math.h>

using namespace std;

#define int long long
#define forn(i, x, n) for (int i = x; i <= n; ++i)
#define for1(i, n, x) for (int i = n; i >= x; --i)
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll MOD = 7;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
}

vi adj[N];
int subcount[N];

void dfs(int cur)
{
    if (adj[cur].size())
    {
        for (auto child : adj[cur])
        {
            dfs(child);
        }
        for (auto child : adj[cur])
        {
            subcount[cur] += (subcount[child] + 1);
        }
    }
}

signed main()
{
    cin.tie(0);
    string name = "";
    // setIO(name);

    // int t;
    // cin >> t;
    // int a = 1;
    // while (t--)
    // {
    //     solve();
    // }

    int n;
    cin >> n;
    forn(i, 1, n - 1)
    {
        int a;
        cin >> a;
        adj[--a].pb(i);
    }
    dfs(0);
    forn(i, 0, n - 1)
    {
        printf("%ld%s", subcount[i], (i == n - 1 ? "" : " "));
    }
    return 0;
}