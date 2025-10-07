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

vector<int> store;
signed main()
{
    // setIO(name);
    int n;
    int count = 1;
    int ans[6000];
    set<int> S;
    S.insert(1);
    for (auto itr = S.begin(); itr != S.end() && count < 6000; itr++, count++)
    {
        ans[count] = *itr;
        S.insert((*itr * 2));
        S.insert((*itr * 3));
        S.insert((*itr * 5));
        S.insert((*itr * 7));
    }

    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        if (n % 100 == 11 || n % 100 == 12 || n % 100 == 13)
        {
            printf("The %lldth humble number is %lld.\n", n, ans[n]);
        }
        else if (n % 10 == 1)
        {
            printf("The %lldst humble number is %lld.\n", n, ans[n]);
        }
        else if (n % 10 == 2)
        {
            printf("The %lldnd humble number is %lld.\n", n, ans[n]);
        }
        else if (n % 10 == 3)
        {
            printf("The %lldrd humble number is %lld.\n", n, ans[n]);
        }
        else
        {
            printf("The %lldth humble number is %lld.\n", n, ans[n]);
        }
    }
    return 0;
}