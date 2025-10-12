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
    int n, m, q;
    cin >> n >> m >> q;
    int dist[600][600];
    forn(i, 0, n)
    {
        forn(j, 0, n)
        {
            dist[i][j] = (i == j ? 0 : 1e18);
            dist[j][i] = (i == j ? 0 : 1e18);
        }
    }
    forn(i, 0, m - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[b][a]);
    }
    forn(k, 1, n)
    {
        forn(i, 1, n)
        {
            if (i == k)
                continue;
            else
                forn(j, i + 1, n)
                {
                    if (j == k)
                        continue;
                    else
                    {
                        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                        dist[j][i] = dist[i][j];
                    }
                }
        }
    }
    forn(i, 1, q)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] >= 1e18)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[a][b] << endl;
        }
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