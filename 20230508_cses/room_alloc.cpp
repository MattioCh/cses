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

    std::priority_queue<int, vector<int>, greater<int>> mypq;

    mypq.push(10);
    mypq.push(20);
    mypq.push(15);

    std::cout << "mypq.top() is now " << mypq.top() << '\n';

    int n;
    cin >> n;
    vector<pii> p;

    forn(i, 1, n)
    {

        int a, d;
        cin >> a >> d;

        p.pb({a, -i}), p.pb({d, i});
    }

    sort(all(p));
    int cnt = 0, ans[n + 1];

    priority_queue<int, vector<int>, greater<int>> pq;

    forn(i, 0, 2 * n - 1)
    {
        if (p[i].S < 0)
        {
            if (pq.empty())
                cnt++, ans[-p[i].S] = cnt;

            else
                ans[-p[i].S] = pq.top(), pq.pop();
        }
        else
            pq.push(ans[p[i].S]);
    }

    cout << cnt << '\n';

    forn(i, 1, n) cout << ans[i] << ' ';
}