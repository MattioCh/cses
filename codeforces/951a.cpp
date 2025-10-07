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

void solve()
{
    int n;
    cin >> n;
    vi v(n);
    forn(i, 0, n - 1)
    {
        cin >> v[i];
    }

    int min = 1e10;
    forn(i, 0, n - 2)
    {
        int max_ = max(v[i], v[i + 1]);
        if (max_ < min)
        {
            min = max_;
        }
    }

    cout << min - 1 << endl;
}


signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // 1100, [1101, 1110, 1111, 1011, 1001, 1010, 1011, ]
    // 0011, [1111, 0001, 0000, 0111, 0110, ]
    // 111001
    // 100101
    // 11010 = 2 + 8 + 16
}