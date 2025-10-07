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

vector<vi> adj;
ll ans[200006];
ll dp[200006];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int a, b;
    cin >> a >> b;
    int gcdd = gcd(a, b);
    if (a == 1)
    {
        cout << b * b << endl;
        return;
    }
    else if (gcdd == 1)
    {
        cout << a * b << endl;
    }
    else if (b % a == 0)
    {
        cout << b * b / a << endl;
        return;
    }
    else
    {
        cout << b * a / gcdd << endl;
        return;
    }
}

signed main()
{
    string name = "";
    // setIO(name);
    // not solved

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}