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

int n, ans = 0;
vi adj[ll(2e5)];
vi sub_count(2e5);

void dfs(int node){
    sub_count[node] = 1;
    for(auto y: adj[node]){
            dfs(y);
            sub_count[node] += sub_count[y];
    }
}


int main()
{
    setIO();
    cin>>n;
    forn(i, 1, n-1){
        int a;
        cin>>a;
        adj[--a].pb(i);
    }

    dfs(0);

    forn(i, 0, n-1){
        cout<<sub_count[i] -1 <<" ";
    }
}