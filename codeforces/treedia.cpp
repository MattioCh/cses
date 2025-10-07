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
int vis[N];
int dist[N];
int dist_to_max_node_1[N];
int dist_to_max_node_2[N];

void dfs(int cur)
{
    vis[cur] = 1;
    for (auto child : adj[cur])
    {
        if (vis[child])
        {
            continue;
        }
        dist[child] = dist[cur] + 1;
        dfs(child);
    }
};

int largest_index_in_dist(int size)
{
    int max_index = 0;
    if (size == 1)
    {
        return 0;
    }
    int max = dist[0];
    forn(i, 1, size - 1)
    {
        if (dist[i] > max)
        {
            max_index = i;
            max = dist[i];
        }
    }
    return max_index;
}

void reset_vis()
{
    fill(begin(vis), end(vis), 0);
    fill(begin(dist), end(dist), 0);
}

signed main()
{
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n - 2)
    {
        int a, b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    dfs(0);
    int max_node_1 = largest_index_in_dist(n);
    reset_vis();

    dfs(max_node_1);
    forn(i, 0, n - 1)
    {
        dist_to_max_node_1[i] = dist[i];
    }
    int max_node_2 = largest_index_in_dist(n);
    reset_vis();

    dfs(max_node_2);
    forn(i, 0, n - 1)
    {
        dist_to_max_node_2[i] = dist[i];
    }
    reset_vis();

    int final_dist[n];
    forn(i, 0, n - 1)
    {
        final_dist[i] = max(dist_to_max_node_1[i], dist_to_max_node_2[i]);
    }

    for (auto d : final_dist)
    {
        printf("%lld ", d);
    }

    return 0;
}