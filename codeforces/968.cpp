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
    int a;
    cin >> a;
    string s;
    cin >> s;

    std::unordered_map<char, int> charCount;
    for (char c : s)
    {
        charCount[c]++;
    }

    std::vector<std::pair<int, char>> charFreq;
    for (auto &[c, count] : charCount)
    {
        charFreq.emplace_back(-count, c);
    }
    std::sort(charFreq.begin(), charFreq.end());

    std::string result;
    for (auto &[count, c] : charFreq)
    {
        result += std::string(abs(count), c);
    }

    for (int i = 1; i < result.length(); i += 2)
    {
        std::swap(result[i - 1], result[i]);
    }

    cout << result << endl;
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