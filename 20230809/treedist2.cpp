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


vector<vi> adj;
ll ans[200006];
ll dp[200006];
int n;
void dfs1(int u, int p=-1,ll depth=0){
    ans[0] += depth;
    dp[u] = 1;
    for(auto a: adj[u]){
        if(a == p) continue;    
        dfs1(a, u, depth+1);
        dp[u] += dp[a];
    }
}

void dfs2(int u, int p=-1){
    for(auto a: adj[u]){
        if(a == p) continue;
        ans[a] = ans[u] + n - dp[a] - dp[a];
        dfs2(a, u);
    }
}


signed main()
{
    string name = "";
    // setIO(name);
    //not solved

    cin>>n;
    // if(n==1){
    //     cout<<0<<endl;
    //     return 0;
    // }
    adj = vector<vi> (n);
    forn(i, 0,n-2){
        int a,b;
        cin>>a>>b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    dfs1(0);
    dfs2(0);
    
    forn(i, 0, n-1) cout<<ans[i]<<" ";
    
}