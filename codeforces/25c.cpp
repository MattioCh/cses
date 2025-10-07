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

ll MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    int max_ = 0;
    int min_ = 0;
    while (n--)
    {
        int a;
        cin >> a;
        if (a >= 0)
        {
            max_ += a;
            min_ += a;
        }
        else
        {
            min_ += a;
            if (-a > max_)
            {
                max_ = -a - max_;
            }
            else
            {
                max_ = max_ + a;
            }
            max_ = max_ > -min_ ? max_ : -min_;
        }
    }
    cout << (max_ > -min_ ? max_ : -min_) << endl;
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