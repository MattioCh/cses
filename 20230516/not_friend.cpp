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

int n, m;

int color[N];
vi adj[N];
vector<pii> rtb;
bool impossible = false;
void dfs(int node, int col){
    if(color[node] != 0) return;
    color[node] = col;
    int next_col = (col == 1) ?2:1;
    for(auto y :adj[node]){
        if(color[y] == col) {impossible=true; return;}
        if(color[y] == 0){dfs(y, next_col);}
    }
}


int main()
{
    // setIO("div7");
    // dfs? dynamic programming, what am I missing?
    // ans: nothing special, sort it, if the cur sum+1 is smaller than next number
    cin>>n>>m;
    forn(i, 0 , m-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    forn(i, 1, n){
        dfs(i, 1);
    }

    if(impossible) cout<<"IMPOSSIBLE";
    else{
        forn(i, 1, n) cout<<color[i]<<" ";
    }
}