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

// void setIO(string name = "")
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     if (!name.empty())
//     {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    int arr[n];
    int dp[n];
    forn(i, 0, n - 1)
    {
        cin >> arr[i];
    }
    int cursum = (l <= arr[0] && arr[0] <= r) ? 0 : arr[0] > r ? 0
                                                               : arr[0];
    dp[0] = (l <= arr[0] && arr[0] <= r) ? 1 : 0;

    forn(i, 1, n - 1)
    {
        cursum += arr[i];
        if ((l <= arr[i] && arr[i] <= r) || (l <= cursum && cursum <= r))
        {
            dp[i] = dp[i - 1] + 1;
            cursum = 0;
        }
        else if (arr[i] > r)
        {
            dp[i] = dp[i - 1];
            cursum = 0;
        }
        else if (cursum > r)
        {
            dp[i] = dp[i - 1];
            cursum = 0;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    printf("hihi %llu ok\n", dp[n - 1]);
    // cout << dp[n - 1] << endl;
    return;
}

signed main()
{
    string name = "";
    // setIO(name);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}