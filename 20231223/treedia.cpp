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
int n;
int dist1[200006], dist2[200006];
int fur1 =0 , fur2 =0 , fur = 0;

int dfs1(int u , int p){
    for(auto a : adj[u]){
        if(a == p) return fur;
        dist[a] = dist[u] +1; 
        if(dist[a] > dist[fur]) fur = a;
        dfs(a, u);
    }
    return fur;
}

void solve(){
    cin>>n;
    adj = vector<vi>(n);
    forn(i, 0 , n-2){
        int a, b;
        cin>>a>>b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    fur1 = dfs1(0, -1);
    forn(i, 0 , n-1) dist1[i] =0;
    fur2 = dfs1(fur2, -1);
    dfs2(fur2, -1)
    forn(i, 0, n-1) cout<<

}


signed main()
{
    string name = "";
    // setIO(name);
    // not solved
    solve();
    return 1;
}