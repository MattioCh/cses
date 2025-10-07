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
const int MAXN = 1e6;
int n, m;
int vis[MAXN];
vector<int> adj[MAXN];

void reset_vis()
{
    for (int i = 0; i <= n; i++)
    {
        vis[i] = false;
    }
}

bool dfs(int i, int root)
{
    if (i == root & vis[i] == true)
        return true;
    if (vis[i])
        return false;
    vis[i] = true;
    bool cycle = false;
    for (auto u : adj[i])
    {
        if (dfs(u, root))
            return true;
        ;
    }

    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        reset_vis();
        cycle = cycle | dfs(i, i);
        if (cycle)
            break;
    }
    cout << (cycle ? "O______O" : "W+W") << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}