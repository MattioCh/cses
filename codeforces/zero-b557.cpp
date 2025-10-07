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
#include <stack>

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

// void setIO(string name = "")
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     if (!name.empty())
//     {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

void solve()
{
    int n;
    cin >> n;
    vi v;
    int arr[10001];
    forn(i, 0, n - 1)
    {
        int a;
        cin >> a;
        int pow2 = pow(a, 2);
        if (arr[pow2])
        {
            v.pb(pow2);
            arr[pow2]++;
        }
        else
        {
            arr[pow2] = 1;
        };
    }
    sort(all(v));
    int ans = 0;
    forn(i, 0, v.size() - 1)
    {
        forn(j, i + 1, v.size() - 1)
        {
            int long2 = v[i] + v[j];
            if (arr[long2])
                ans += arr[i] * arr[j] * arr[long2];
        }
    }

    cout << ans << "\n";
    return;
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