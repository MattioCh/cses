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
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int number_of_zero_in_even_index_in_s2 = 0;
    int number_of_zero_in_odd_index_in_s2 = 0;
    int number_of_one_in_even_index_in_s1 = 0;
    int number_of_one_in_odd_index_in_s1 = 0;
    forn(i, 0, n - 1)
    {
        if (s1[i] == '1')
        {
            if (i % 2)
            {
                number_of_one_in_odd_index_in_s1++;
            }
            else
            {
                number_of_one_in_even_index_in_s1++;
            }
        }
    }
    forn(i, 0, n - 1)
    {
        if (s2[i] == '0')
        {
            if (i % 2)
            {
                number_of_zero_in_odd_index_in_s2++;
            }
            else
            {
                number_of_zero_in_even_index_in_s2++;
            }
        }
    }
    if (number_of_zero_in_even_index_in_s2 >= number_of_one_in_odd_index_in_s1 &&
        number_of_zero_in_odd_index_in_s2 >= number_of_one_in_even_index_in_s1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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