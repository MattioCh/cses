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

bool is_in_dist(int x1, int y1, int x2, int y2, int d)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0) <= d;
}

int ans = 0;
void dfs(int x, int y, vector<vector<vector<pair<int, int>>>> feasible, bool prev_same_level)
{
    if (y == 0)
    {
        ans++;
        if (prev_same_level == false)
        {
            return;
        }
    }
    for (auto path : feasible[x][y])
    {
        if (path.F == x && prev_same_level == false)
        {
            dfs(path.F, path.S, feasible, true);
        }
        else
        {
            dfs(path.F, path.S, feasible, false);
        }
    }
}

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<char>> matrix(n);
    forn(i, 0, n - 1)
    {
        string s;
        cin >> s;
        cout << "ok" << s << "ok";
        forn(j, 0, m - 1)
        {
            matrix[i].push_back(s[j]);
        }
        cout << "HI";
    }
    vector<int> start_path;
    forn(i, 0, m - 1)
    {
        if (matrix[n - 1][i] == 'X')
        {
            start_path.push_back(i);
        }
    }
    cout << "HI2";
    vector<vector<vector<pair<int, int>>>> feasible_next_step(n, vector<vector<pair<int, int>>>(m));
    for (int i = n; i >= 1; i--)
    {
        forn(j, 0, m - 1)
        {
            forn(k, 0, m - 1)
            {
                if (i - 1 >= 0)
                {
                    if (is_in_dist(i, j, i - 1, k, d))
                    {
                        feasible_next_step[i][j].push_back({i - 1, k});
                    }
                }

                if (is_in_dist(i, j, i, k, d) && j != k)
                {
                    feasible_next_step[i][j].push_back({i, k});
                }
            }
        }
    }
    ans = 0;
    for (auto start : start_path)
    {
        dfs(0, start, feasible_next_step, false);
    }
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    string name = "";
    // setIO(name);

    int t;
    cin >> t;
    int a = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}