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

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    char first = s[0];
    forn(i, 1, n - 1)
    {
        if (first != s[i] || n % 2 == 1)
        {
            cout << "0" << endl;
            return;
        }
    }
    int ans = 1;
    forn(i, 2, n - 1)
    {
        if (n % i == 0 && (n / i) % 2 == 0)
            ans++;
    }
    cout << ans << endl;
    string res = "";
    forn(i, 0, n/2 -1)
        res += first;
    cout<<res<<" ";
    forn(i, 2, n - 1)
    {
        if (n % i == 0 && (n / i) % 2 == 0){
            
        }
    }
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