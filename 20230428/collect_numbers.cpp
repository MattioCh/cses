#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

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

int main()
{
    // setIO("div7");
    // dfs? dynamic programming, what am I missing?
    // ans: nothing special, sort it, if the cur sum+1 is smaller than next number

    int n, k;
    cin >> n >> k;
    vi arr, arr2(n);
    forn(i, 0, n - 1)
    {
        ll val;
        cin >> val;
        arr.pb(val);
        arr2[--val] = i;
    }

    ll a, b;
    cin >> a >> b;
    a--, b--;
    arr2[--arr[a]] = b;
    arr2[--arr[b]] = a;
    ll count = 1;
    forn(i, 1, n - 1)
    {
        if (arr2[i - 1] > arr2[i])
        {
            count++;
        }
    }

    forn(j, 1, k)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        arr2[--arr[a]] = b;
        arr2[--arr[b]] = a;


        cout << count << endl;
    }
}