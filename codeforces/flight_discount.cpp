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
const int B = 1e18 + 7;

ll MOD = 7;

vector < pair<long long, int> G;
int dist[N];
int vis[N];
int cur_largest[N];

int find_target()
{
    int idx = -1;
    int minE = INF;
    forn(i, 0, n - 1)
    {
        if (vis[i])
            continue;
        if (dist[i] < minE)
        {
            idx = i;
            minE = dist[i];
        }
    }
    return idx;
}

void Dig(int n)
{
    fill(dist, dist + N, INF);
    fill(vis, vis + N, 0);
    fill(cur_largest, cur_largest + N, -1);
    vis[0] = 1;
    forn(i, 0, n - 1)
    {
        int u = find_target();
        vis[u] = 1;
        for (auto v : G[u])
        {
            w = v.first;
            node = v.second;
            if (vis[node])
                continue;
            dist[node] = min(dis[node], dist[u] + w);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    forn(i, 0, m - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[--a].pb({c, --b});
    }
    Dig(0);
}

signed main()
{
    string name = "";
    // setIO(name);
    int t;
    cin >> t;

    solve();
    return 0;
}