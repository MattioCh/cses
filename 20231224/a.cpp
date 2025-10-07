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

void solve()
{
    int x;
    cin >> x;
    vi v(x);
    int all_pos = 1;
    int count_neg = 0;
    int have_zero = 0;
    int neg_index = -1;

    forn(i, 0, x - 1)
    {
        cin >> v[i];
        if (v[i] < 0)
        {
            all_pos = 0;
            count_neg++;
            if (count_neg == 1)
            {
                neg_index = i;
            }
        }
        if (v[i] == 0)
        {
            have_zero = 1;
        }
    }
    if (have_zero || count_neg % 2)
    {
        cout << 0 << endl;
    }
    else if (all_pos)
    {
        cout << 1 << endl
             << "1 0" << endl;
    }
    else
    {
        cout << 1 << endl
             << neg_index + 1 << " " << 0 << endl;
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