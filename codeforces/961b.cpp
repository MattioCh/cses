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
    int n, k;
    cin >> n >> k;
    int arr[n];
    map<int, int> mp;
    forn(i, 0, n - 1)
    {
        int a;
        cin >> a;
        arr[i] = a;
        mp[a]++;
    }
    int max_ = -1;
    for (auto it : mp)
    {
        if (mp.find(it.first - 1) != mp.end())
        {
            int x = mp[it.first];
            int y = mp[it.first - 1];
            int temp_max = 0;
            while (x > 0 && temp_max <= k - it.first)
            {
                temp_max += it.first;
                x--;
            }
            while (y > 0 && temp_max <= k - (it.first - 1))
            {
                temp_max += it.first - 1;
                y--;
            }
            max_ = max(max_, temp_max);
        }
        else
        {
            max_ = max(max_, min((k / it.first), it.second) * it.first);
        }
    }
    // cout << max_ << endl;
    printf("%ld\n", max_);
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