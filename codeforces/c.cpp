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

void solve()
{
    int n;
    cin >> n;
    vi v(n + 1), odd(n + 1, 0), prefix_sum(n + 1, 0);
    int ans = 0;
    forn(i, 1, n)
    {
        cin >> v[i];
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }
    int oddc = 0;
    forn(i, 1, n)
    {
        if (v[i] % 2)
        {
            oddc++;
        }

        if (i == 1)
        {
            cout << v[i] << " ";
        }
        else if (i == 2)
        {
            cout << prefix_sum[i] / 2 * 2 << " ";
        }
        else
        {
            int weird = 0;
            if (oddc % 3 == 1)
            {
                weird = -(oddc % 3);
            }
            else
            {
                weird = 0;
            }
            cout << (prefix_sum[i] + weird) / 2 * 2 << " ";
        }
    }

    cout << endl;
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