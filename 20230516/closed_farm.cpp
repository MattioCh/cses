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

int n,m,a,b,k,ans;
vi adj[N];
bool visited[N], closed[N];

void dfs(int node){
    visited[node] =true;
    for(int x : adj[node]){
        if(!closed[x] && !visited[x]){
            dfs(x);
        }
    }
}

void count_comps(){
    ans = 0;
    forn(i, 1, n){
        if(!closed[i] && !visited[i]){
            dfs(i);
            ans++;
        }
    }

    if(ans > 1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    setIO("closing");
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    forn(i, 0,n-1){
        count_comps();
        cin>>k;
        closed[k] = true;
        forn(i, 1, N) visited[i] = false;
    }


}