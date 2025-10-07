#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <unordered_map>

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

int binomial(int n, int k, int p)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    forn(i, 0, n)
    {
        dp[i][0] = 1;
        if (i <= k)
        {
            dp[i][i] = 1;
        }
    }

    forn(i, 0, n)
    {
        forn(j, 1, min(i, k))
        {
            if (i != j)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
            }
        }
    }

    return dp[n][k];
}

signed main()
{
    string name = "";
    // setIO(name);
    // not solved

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    cout << binomial(10, 3, N);
    return 0;
}