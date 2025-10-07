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
bool visited[N];
vi adj[N];
vector<pii> rtb;

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;
    for(auto neigh : adj[node]){
        dfs(neigh);
    }
}


int main()
{
    // setIO("div7");
    cin>>n>>m;
    forn(i, 0, m-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);

    forn(i ,1, n){
        if(!visited[i]){
            adj[1].pb(i);
            adj[i].pb(1);
            rtb.pb({1,i});
            dfs(i);
        }
    }

    cout<<rtb.size()<<endl;
    for(auto road : rtb){
        cout<<road.first<<" "<<road.second<<endl;
    }


}