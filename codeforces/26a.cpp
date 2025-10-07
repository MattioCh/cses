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
    if (v[0] == v[n - 1])
    {
        cout << "NO" << endl;
        return;
    }
    int first_diff_index = -1;
    forn(i, 0, n - 2)
    {
        if (first_diff_index == -1 && v[i] == v[i + 1])
        {
            first_diff_index = i;
        }
    }
    if (first_diff_index == -1)
    {
        first_diff_index = n - 1;
    }
    cout << "YES" << endl;
    forn(i, 0, n - 1)
    {
        if (i != first_diff_index)
        {
            cout << "R";
        }
        else
        {
            cout << "B";
        }
    }
    cout << endl;
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