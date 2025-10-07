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
#include <stack>

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

bool solve2(int n)
{
    stack<int> st1;
    stack<int> st2;
    forn(i, 1, n)
    {
        st1.push(n - i + 1);
    }
    forn(i, 1, n)
    {
        int b;
        cin >> b;
        if (b == 0)
        {
            return false;
        }
        if (st2.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        else if (st2.empty() && st1.empty())
        {
            cout << "Yes" << endl;
            return true;
        }

        if (st2.top() == b)
        {
            st2.pop();
        }
        else
        {
            while (st2.top() != b)
            {
                if (st1.empty())
                {
                    cout << "No" << endl;
                    return true;
                }
                st2.push(st1.top());
                st1.pop();
            }
            if (st2.top() == b)
            {
                st2.pop();
            }
        }
    }
    cout << "Yes" << endl;
    return true;
}

void solve(int n)
{
    bool cont = true;
    while (cont)
    {
        cont = solve2(n);
    }

    return;
}

signed main()
{
    string name = "";
    // setIO(name);

    // int t;
    // cin >> t;
    int a;
    int c = 0;
    while (true)
    {
        int a;
        cin >> a;
        if (a == 0)
            return 0;
        if (c != 0)
        {
            cout << endl;
        }
        c++;
        solve(a);
    }
    return 0;
}