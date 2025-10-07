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
    int a, b;
    cin >> a >> b;
    int ar[100], br[100];
    forn(i, 0, 100)
    {
        if (a)
        {
            ar[i] = a & 1;
        }
        else
        {
            ar[i] = -1;
        }
        a >>= 1;
    }
    forn(i, 0, 100)
    {
        if (b)
        {
            br[i] = b & 1;
        }
        else
        {
            br[i] = -1;
        }
        b >>= 1;
    }
    int cr[100];
    forn(i, 0, 100)
    {
        if(ar[i] != -1 )
        cr[i] = !(ar[i] && br[i]);
    }
    int ans = 0;
    forn(i, 0, 100)
    {
        if (cr[i] == 1)
        {
            ans = i;
            break;
        }
    }
    cout << pow(2, ans) << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // 1100
    // 0011
    // 111001
    // 100101

    // 11010 = 2 + 8 + 16
}