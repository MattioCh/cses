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

void solve()
{
    int street_len;
    int light_num;
    cin>>street_len>>light_num;
    
    set<int> lights{0, street_len};
    multiset<int> dist{street_len};

    forn(i, 0 , light_num-1){
        int pos;
        cin>>pos;
        
        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;
        it2--;
        dist.erase(dist.find(*it1 - *it2));
        dist.insert(pos - *it2);
        dist.insert(*it1 - pos);
        lights.insert(pos);

        auto ans = dist.end();
        ans--;
        cout<<*ans<<" ";
    }
}

int main()
{
    // setIO("div7");
    // dfs? dynamic programming, what am I missing?
    // ans: nothing special, sort it, if the cur sum+1 is smaller than next number
    solve();
}