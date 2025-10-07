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

int compute_cost(string s)
{
    // cout << s << endl;
    int n = s.length();
    int transitions = 0;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] != s[i - 1])
            transitions++;
    }
    // cout << s << (n + (s[0] == '1' ? 1 : 0) + transitions) << endl;
    return n + (s[0] == '1' ? 1 : 0) + transitions;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int last_index_of_longest_one = -1;
    int largest_one = 0;
    int last_index_of_second_one = -1;
    int second_largest_one = 0;
    int cur = 0;
    int count_one = 0;
    // cout << compute_cost("1101010010011011100") << endl;
    // cout << compute_cost("1101010010011111000") << endl;
    vi costs = {compute_cost(s)};
    int transition = 0;
    forn(i, 1, n - 1)
    {
        if (s[i] != s[i - 1])
            transition++;
    }
    forn(i, 0, n - 1)
    {
        if (s[i] == '0')
        {
            int change = 0;
            if (i >= 1)
            {
                change -= (s[0] != s[1] ? 1 : 0);
                change += (s[i] != s[i - 1] ? 1 : 0);
            }
            if (i < s.length() - 1)
            {
                change -= (s[i] != s[i + 1] ? 1 : 0);
                change += (s[0] != s[i + 1] ? 1 : 0);
            }
            costs.push_back(n + transition + change);
        }
    }
    cout << *min_element(all(costs)) << endl;
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