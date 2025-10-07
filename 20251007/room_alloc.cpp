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
    int n;
    cin >> n;
    vi ans(n);
    vector<pair<pair<int, int>, int>> store(n);
    forn(i, 0, n - 1)
    {
        cin >> store[i].first.first >> store[i].first.second;
        store[i].second = i;
    }
    sort(store.begin(), store.end());
    int last_room = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    forn(i, 0, n - 1)
    {
        if (pq.empty() || pq.top().first >= store[i].first.first)
        {
            last_room++;
            pq.push({store[i].first.second, last_room});
            ans[store[i].second] = last_room;
        }
        else
        {
            auto min = pq.top();
            pq.pop();
            pq.push({store[i].first.second, min.second});
            ans[store[i].second] = min.second;
        }
    }
    cout << last_room << endl;
    forn(i, 0, n - 1)
    {
        cout << ans[i] << " ";
    }
}

signed main()
{
    cin.tie(0);
    string name = "";
    // setIO(name);

    int t = 1;
    // cin >> t;
    int a = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}