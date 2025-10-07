#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
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


int main()
{
    // setIO("div7");
    // dfs? dynamic programming, what am I missing?
    // ans: nothing special, sort it, if the cur sum+1 is smaller than next number

    int n;
    cin >> n;

    vector<vi> arr;
    // save query
    forn(i, 1, n)
    {
        int a, d;
        cin >> a >> d;
        arr.pb({a, d});
    }

    sort(all(arr));
    ll ans = 0, cur_time = 0;

    forn(i, 0, n-1){
        // cout<<arr.front()[1]<<"hi"<<arr.front()[0]<<"bye"<<endl;
        cur_time += arr[i][0];
        ans += arr[i][1] - cur_time;
    }
    cout << ans << endl;
}