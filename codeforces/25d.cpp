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

vi store;

int find_max()
{
    int max_ = 0;
    int min_ = 0;
    int nn = store.size();
    forn(i, 0, nn - 1)
    {
        int a = store[i];
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
    return (max_ > -min_ ? max_ : -min_);
}

int n;
int dfs(int i, int max_, int cur_sum)
{
    if (i == n)
    {
        if (cur_sum == max_)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int the_sum = cur_sum + store[i];
    if (store[i] >= 0 || the_sum >= 0)
    {
        return (dfs(i + 1, max_, the_sum) * 2) % MOD;
    }
    else
    {
        return dfs(i + 1, max_, cur_sum + store[i]) + dfs(i + 1, max_, abs(cur_sum + store[i])) % MOD;
    }
}

void solve()
{
    cin >> n;
    store.clear();
    forn(i, 0, n - 1)
    {
        int a;
        cin >> a;
        store.pb(a);
    }
    int max_ = find_max();
    int res_count = dfs(0, max_, 0);
    printf("%lld\n", res_count);
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