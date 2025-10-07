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
int max_ = 10000009;
int is_prime[10000009];
int steps[10000009];
int dp[10000009];

void find_prime()
{
    forn(i, 0, max_ - 1)
    {
        is_prime[i] = -1;
        steps[i] = 0;
        dp[i] = 0;
    }
    int i = 2;
    while (i < max_)
    {
        if (is_prime[i] == -1)
        {
            is_prime[i] = 1;
            int j = 2;
            while (i * j < max_)
            {
                is_prime[i * j] = 0;
                steps[i * j]++;
                j++;
            }
        }

        i++;
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

signed main()
{
    cin.tie(0);
    string name = "";
    // setIO(name);

    int t;
    cin >> t;
    int a = 1;
    find_prime();
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 4;
    forn(i, 6, max_ - 1)
    {
        if (is_prime[i])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = dp[i - 1] + steps[i];
        }
        // cout << i << " " << dp[i] << " " << steps[i] << endl;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}