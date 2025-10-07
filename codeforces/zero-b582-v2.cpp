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
const int MAXN = 1e4;
int n, m;
int vis[MAXN];
vector<int> adj[MAXN];
int din[MAXN];

void calculate_in_degree()
{
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            din[v]++;
        }
    }
}

bool topological_sort()
{
    calculate_in_degree();
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if (din[i] == 0)
            que.push(i);
    }

    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (auto v : adj[u])
        {
            din[v]--;
            if (din[v] == 0)
            {
                que.push(v);
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (din[i] > 0)
            return true;
    }
    return false;
}

void solve()
{

    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        din[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    bool ans = topological_sort();
    cout << (ans ? "O______O" : "W+W") << endl;
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