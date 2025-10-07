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
int ind[MAXN];

void calculate_ind()
{
    for (int i = 1; i <= n; i++)
    {
        for (auto v : adj[i])
        {
            ind[v]++;
        }
    }
}

void dfs_and_print(int i; int root)
{
    if (vis[i] && i == root)
    {
        cout << i << endl;
        return;
    }
    if (vis[i])
        return;
    vis[i] = 1;
    cout << i << endl;
    for (auto v : adj[i])
    {
        dfs(v, root);
    }

    return;
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
    caculate_in_degree();
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] > 0)
        {
            a = i;
            break;
        }
    }
    dfs_and_print(a, a);
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
/*


*/