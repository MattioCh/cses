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
    int arr[n];
    int min_ = 5001;
    int min_index = 0;
    int exist_zero = 0;
    forn(i, 0, n - 1)
    {
        cin >> arr[i];
        if (min_ > arr[i] && i >= 3)
        {
            min_ = arr[i];
            min_index = i;
        }
    }
    int arr2[4] = {arr[0], arr[1], arr[2], min_};
    int has_zero = 0;
    forn(i, 0, 3)
    {
        if (arr2[i] == 0)
            has_zero++;
    }
    if (has_zero == 0)
    {
        if (n == 4)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << 4 << " " << n << endl;
        }
        cout << 1 << " " << 4 << endl;
        return;
    }
    if (has_zero == 1)
    {
        if (arr2[0] == 0 || arr2[1] == 0 || arr2[2] == 0)
        {
            if (n == 4)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
                cout << 4 << " " << n << endl;
            }
            cout << 1 << " " << 3 << endl;
            cout << 1 << " " << 2 << endl;
            return;
        }
        else
        {
            if (n == 4)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
                cout << 4 << " " << n << endl;
            }
            cout << 2 << " " << 4 << endl;
            cout << 1 << " " << 2 << endl;
            return;
        }
    }
    if (has_zero == 3 || has_zero == 4)
    {
        if (n == 4)
        {
            cout << 3 << endl;
        }
        else
        {
            cout << 4 << endl;
            cout << 4 << " " << n << endl;
        }
        cout << 3 << " " << 4 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    if (has_zero == 2)
    {
        if (arr2[0] == 0 && arr2[1] == 0)
        {
            if (n == 4)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
                cout << 4 << " " << n << endl;
            }
            cout << 1 << " " << 3 << endl;
            cout << 1 << " " << 2 << endl;
            return;
        }
        if (arr2[2] == 0 && arr2[3] == 0)
        {
            if (n == 4)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
                cout << 4 << " " << n << endl;
            }
            cout << 2 << " " << 4 << endl;
            cout << 1 << " " << 2 << endl;
            return;
        }
        else
        {
            if (n == 4)
            {
                cout << 3 << endl;
            }
            else
            {
                cout << 4 << endl;
                cout << 4 << " " << n << endl;
            }
            cout << 3 << " " << 4 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 1 << " " << 2 << endl;
            return;
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