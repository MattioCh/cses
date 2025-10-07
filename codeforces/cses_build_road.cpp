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
vector<int> extra_road;

void dfs(int i)
{
    if (vis[i])
        return;
    vis[i] = 1;
    for (auto u : adj[i])
    {
        dfs(u);
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
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            adj[1].push_back(i);
            adj[i].push_back(1);
            extra_road.push_back(i);
            dfs(i);
        }
    }
    cout << extra_road.size() << endl;
    for (auto u : extra_road)
    {
        cout << 1 << " " << u << endl;
    }
}