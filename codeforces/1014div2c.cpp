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
    string s;
    cin >> s;
    int lc = 0, li = 0, lt = 0;
    forn(i, 0, n - 1)
    {
        if (s[i] == 'L')
            lc++;
        else if (s[i] == 'T')
            lt++;
        else
            li++;
    }
    int max_of_each = max(max(li, lt), lc);
    int needL = max_of_each - lc;
    int needI = max_of_each - li;
    int needT = max_of_each - lt;
    int needed = needL + needI + needT;
    if (needed == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (needed > 2 * n)
    {
        cout << -1 << endl;
        return;
    }
    vi LI, TL, TI;
    forn(i, 0, n - 2)
    {
        if (s[i] == 'T')
        {
            if (s[i + 1] == 'I')
            {
                TI.push_back(i + 1);
            }
            else
            {
                TL.push_back(i + 1);
            }
        }
        else if (s[i] == "I")
        {
            if (s[i + 1] == "T")
            {
                TL.push_back(-(i + 1));
            }
            else
            {
                LI.push_back(-(i + 1));
            }
        }
        else
        {
            if (s[i + 1] == 'T')
            {
                TL.push_back(-(i + 1));
            }
            else
            {
                LI.push_back(-(i + 1));
            }
        }
    }
    int ans = 0;
    vi op;
    while (needL > 0 || needI > 0 || needT > 0)
    {
        int to_break = 1;
        if (needL > 0 && TI.size() > 0)
        {
            int index = TI.back();
            TI.pop_back();
            if (index > 0)
            {
                TL.push_back(index);
                LI.push_back(index + 1);
            }
            else
            {
                TL.push_back(-index - 1);
                LI.push_back(-index);
            }

            needL--;
            op.push_back(abs(index));
            to_break = 0;
            ans++;
        }
        else if (needT > 0 && LI.size() > 0)
        {
            needT--;
            int index = LI.back();
            LI.pop_back();
            if (index > 0)
            {
                TL.push_back(-index);
                TI.push_back(index + 1);
            }
            else
            {
                TL.push_back(-index - 1);
                LI.push_back(-index);
            }
            op.push_back(index);
            to_break = 0;
            ans++;
        }
        else if (needI > 0 && TL.size() > 0)
        {
            needI--;
            int index = TL.back();
            TL.pop_back();
            TI.push_back(index);
            LI.push_back(index + 1);
            op.push_back(index);
            to_break = 0;
            ans++;
        }
        if (to_break)
            break;
    }
    if (needL > 0 || needI > 0 || needT > 0 || op.size() > 2 * n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << op.size() << endl;
        forn(i, 0, op.size() - 1)
        {
            cout << op[i] << endl;
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