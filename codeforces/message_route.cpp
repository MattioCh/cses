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
#include <stack>

using namespace std;
const int MAXN = 1e5 + 2;
int n, m;
vector<int> adj[MAXN];
int vis[MAXN];
int par[MAXN];
int dist[MAXN];
vector<int> extra_road;

void dfs(int i)
{
    vis[i] = 1;
    if (i == n)
        return;
    for (auto u : adj[i])
    {
        if (dist[i] + 1 < dist[u] || !vis[u])
        {
            par[u] = i;
            dist[u] = dist[i] + 1;
            dfs(u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        dist[i] = 0;
    }
    dfs(1);
    if (vis[n])
    {
        vector<int> sol;
        int cur = n;
        while (cur != 1)
        {
            sol.push_back(cur);
            cur = par[cur];
        }
        cout << sol.size() + 1 << endl;
        cout << 1 << " ";
        for (int i = sol.size() - 1; i >= 0; i--)
        {
            cout << sol[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}