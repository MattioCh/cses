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

int cost(int x)
{
    return pow(3, x + 1) + x * pow(3, x - 1);
}

void solve()
{
    int ans = 0;
    int largest_exponent = 20;
    int x;
    cin >> x;
    while (x > 0 && largest_exponent >= 0)
    {
        // cout << x << endl;
        if (x >= pow(3, largest_exponent))
        {
            // cout << x;
            // cout << "x" << endl;
            ans += (cost(largest_exponent) * ll(x / pow(3, largest_exponent)));
            // cout << "cost" << (x / pow(3, largest_exponent)) << endl;
            x %= ll(pow(3, largest_exponent));
            // cout << largest_exponent << endl;
        }
        largest_exponent -= 1;
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