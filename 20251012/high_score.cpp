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
#include <numeric>

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
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    vector<vector<int>> adj(n + 1);
    forn(i, 0, m - 1)
    {
        int a, b, x;
        cin >> a >> b >> x;
        edges.emplace_back(a, b, x);
        adj[a].push_back(b);
    }
    vi dist(n + 1, -1e18);
    dist[1] = 0;
    forn(iter, 1, n - 1)
    {
        for (auto [a, b, x] : edges)
        {
            if (dist[a] > -1e18 && dist[b] < dist[a] + x)
                dist[b] = dist[a] + x;
        }
    }
    vi can_improve(n + 1, false);
    for (auto [a, b, x] : edges)
    {
        if (dist[a] > -1e18 && dist[b] < dist[a] + x) // inf cycle
            can_improve[b] = true;
    }
    vi vis(n + 1, false);
    queue<int> q;
    forn(i, 1, n)
    {
        if (can_improve[i])
        {
            q.push(i);
            vis[i] = true;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    if (vis[n])
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[n] << endl;
    }
}

signed main()
{
    cin.tie(0);
    string name = "";
    // setIO(name);

    int t = 1;
    // cin >> t;
    int a = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}