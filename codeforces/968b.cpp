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

vi erase(vi vv, int i)
{
    vv.erase(vv.begin() + i);
    return vv;
}

int find_largest_index(vi vv)
{
    int max = vv[0];
    int max_index = 0;
    forn(i, 0, vv.size() - 1)
    {
        if (vv[i] > max)
        {
            max = vv[i];
            max_index = i;
        }
    }
    return max_index;
}

int find_smallest_index(vi vv)
{
    int max = vv[0];
    int max_index = 0;
    forn(i, 0, vv.size() - 1)
    {
        if (vv[i] < max)
        {
            max = vv[i];
            max_index = i;
        }
    }
    return max_index;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    forn(i, 0, n - 1)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    int index = (n) / 2;

    // bool turn = true;
    // while (arr.size() > 1)
    // {
    //     if (turn)
    //     {
    //         int index = find_smallest_index(arr);
    //         arr = erase(arr, index);
    //     }
    //     else
    //     {
    //         int index = find_largest_index(arr);
    //         arr = erase(arr, index);
    //     }

    //     turn = !turn;
    // }

    cout << arr[index] << endl;
    // printf("hi%lddhi", arr[index]);
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