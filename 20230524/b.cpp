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



void solve(){
    int n;cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<2<<endl;
        return;
    }
    set<int> m;
    m.insert(50);
    int cur = 50;
    for(auto y: s){
        if(y == '<'){
            cur++;
            m.insert(cur);
        }else{
            cur--;
            m.insert(cur);
        }
    }

    cout<<m.size()<<endl;
}

// 1<2<3<4>3>2>1>0>-1>-2>-3>-4>-5

int main()
{
    // setIO("mootube");
    //not solved
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}