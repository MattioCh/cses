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
vector<int> adj[200001];
int vis[200001];
int dist[200001];
int p[200001];
signed main()
{
    int n, m;
    cin >> n >> m;
    forn(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
    if (!vis[n])
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    int u = n;
    int K = dist[n];
    vector<int> ans(K + 1);
    for (int i = K; i >= 0; i--)
    {
        ans[i] = u;
        u = p[u];
    }

    printf("%d\n", K + 1);
    for (int i = 0; i <= K; i++)
        printf("%d%c", ans[i], (" \n")[i == K]);

    return 0;
}