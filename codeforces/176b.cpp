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
    int n, k;
    cin >> n >> k;
    int arr[n];
    forn(i, 0, n - 1)
    {
        cin >> arr[i];
    }
    if (k > 1)
    {
        sort(arr, arr + n);
        int ans = 0;
        for (int i = n - 1; i >= n - k - 1; i--)
        {
            ans += arr[i];
        }
        cout << ans << endl;
        return;
    }
    else
    {
        if (n == 2)
        {
            cout << arr[0] + arr[1] << endl;
            return;
        }
        int max_ = arr[1];
        int end = max(arr[0], arr[n - 1]);
        for (int i = 1; i < n - 1; i++)
        {
            max_ = max(max_, arr[i]);
        }
        cout << end + max_ << endl;

        return;
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