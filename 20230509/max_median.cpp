#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include<unordered_map>

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

void largest_true(vi arr, int k){
    ll lo = 0;
    ll hi = 2e9;
    ll ans = 0;
    int med = arr.size()/2;
    while(lo <= hi){
        ll mid = lo + (hi - lo)/2;
        int sum_ops =0;
        for(int i = med; i<arr.size(); i++){
            sum_ops += max(ll(0),  mid - arr[i]);
            if(sum_ops > k) break;
        }

        if(sum_ops > k){
            hi = mid-1;
        }else{
            ans = max(mid, ans);
            lo = mid+1;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    // setIO("div7");
    // dfs? dynamic programming, what am I missing?
    // ans: nothing special, sort it, if the cur sum+1 is smaller than next number

    int n, max_ops;cin>>n>>max_ops;
    vi arr(n);
    forn(i, 0,n-1) cin>>arr[i];

    sort(all(arr));
    largest_true(arr, max_ops);
}