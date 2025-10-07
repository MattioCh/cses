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

int n, m,ans=N, max_n = 250;
vi depths(max_n);
vector<pii> boots(max_n);
vector<vector<bool>> vis(max_n, vector<bool>(max_n));

void dfs(int depth, int boot){
    if(vis[depth][boot]) return;
    vis[depth][boot] = true;

    if(depth == n-1){
        ans = min(boot, ans);
        return;
    }

    for(int i = depth + 1; i<= depth+ boots[boot].S && i< n; i++){
        if(depths[i] <= boots[boot].F) dfs(i, boot);
    }

    forn(i, boot , m-1){
        if(depths[depth] <= boots[i].F) dfs(depth, i);
    }

    
}


int main()
{
    setIO("snowboots");
    cin >> n >> m;
    forn(i, 0,n-1) cin>>depths[i];
    forn(i, 0, m-1){
        int a,b;
        cin>>a>>b;
        boots[i] = {a,b};
    }

    dfs(0, 0);

    cout<<ans<<endl;
}