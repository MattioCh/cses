#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <unordered_map>

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

void solve(int t)
{
    int x = 10;
    int max = -1;
    vector<string> v;
    while (x--)
    {
        string a;
        int b;
        cin >> a >> b;
        if (b == max)
        {
            v.push_back(a);
        }
        else if (b > max)
        {
            while (v.size() > 0)
            {
                v.pop_back();
            }
            v.push_back(a);
            max = b;
        }
    }
    cout << "Case #" << t << ":" << endl;
    for (auto s : v)
    {
        cout << s << endl;
    }
}

signed main()
{
    string name = "";
    // setIO(name);

    int t;
    cin >> t;
    int a = 1;
    while (t--)
    {
        solve(a++);
    }
    return 0;
}