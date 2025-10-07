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

int getSumOfDigit(int n)
{
    int cur = n;
    int sum = 0;
    while (cur)
    {
        sum += pow(cur % 10, 2);
        cur /= 10;
    }
    return sum;
}
int a;
bool trasverse(int n, vi &dp)
{
    if (n == 1 || dp[n] == 1)
    {
        return true;
    }
    int b = getSumOfDigit(n);
    if (b == a || dp[n] == -1)
    {
        dp[b] = -1;
        dp[a] = -1;
        return false;
    }
    bool res = trasverse(b, dp);
    if (res)
    {
        dp[b] = 1;
        return true;
    }
    else
    {
        dp[b] = -1;
        return false;
    }
}
void solve(int c)
{
    cin >> a;
    int cur = a;
    vi v(200, 0);
    v[1] = 1;
    bool res = trasverse(a, v);
    if (res)
    {
        cout << "Case #" << c << ": is a Happy Number." << endl;
    }
    else
    {
        cout << "Case #" << c << ": is an Unhappy Number." << endl;
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