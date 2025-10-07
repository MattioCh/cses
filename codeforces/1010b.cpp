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

void solve()
{

    int x, n, m;
    cin >> x >> n >> m;
    int min_ = x, max_ = x;
    int xx = x, nn = n, mm = m;
    // maximise
    while ((nn > 0 || mm > 0) && xx > 1)
    {
        // cout << "max" << xx;
        if (xx % 2)
        {
            if (mm > 0)
            {
                xx = (xx + 1) / 2;
                mm--;
            }
            else
            {
                xx = xx / 2;
                nn--;
            }
        }
        else
        {
            if (nn > 0)
            {
                xx = xx / 2;
                nn--;
            }
            else
            {
                xx = xx / 2;
                mm--;
            }
        }
        // cout << "end" << xx;
    }
    max_ = (xx == 0 || nn > 0) ? 0 : xx;
    xx = x, nn = n, mm = m;
    // minimise
    while ((nn > 0 || mm > 0) && xx > 1)
    {
        // cout << "min";
        if (xx % 2)
        {
            if (nn > 0)
            {
                xx = (xx / 2);
                nn--;
            }
            else
            {
                xx = (xx + 1) / 2;
                mm--;
            }
        }
        else
        {
            if (mm > 0)
            {
                xx = (xx / 2);
                mm--;
            }
            else
            {
                xx = (xx / 2);
                nn--;
            }
        }
    }
    min_ = (xx == 0 || nn > 0) ? 0 : xx;
    // cout << "max" << max_ << "min" << min_ << endl;
    cout << min_ << " " << max_ << endl;
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