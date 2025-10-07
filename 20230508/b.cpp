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


void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> table(n, vector<int>(m, -1));
    int arr[n*m];
    forn(i,1, n*m){
        cin>>arr[i-1];
    }

    sort(arr, arr+n*m);


    int max_num = arr[n*m-1];

    if( n==1 || m==1){
        int min_num = arr[0];
        cout<< (max_num- min_num) * (max(m,n) -1)<<endl;
    }else{
        int min1_num = arr[0];
        int min2_num = arr[1];
        int ans1 = (max_num-min2_num)*(min(n,m)-1) + (max_num -min1_num)*(max(n,m)-1)*min(n,m);
        int max1 = arr[n*m-1];
        int max2 = arr[n*m-2];
        int ans2 = (max2-arr[0])*(min(n,m)-1) + (max1 - arr[0])*(max(n,m)-1)*min(n,m);
        int res = max(ans1, ans2);
        cout<<res<<endl;
    }
// 0 13 13
// 3 13 13

// 10  -3  9
// 7   8   8

// -3 7 8 8 9 10

// 8 -7 .
// -3 . .
}

int main()
{
    // setIO("div7");
    // dfs? dynamic programming, what am I missing?
    // ans: nothing special, sort it, if the cur sum+1 is smaller than next number

    int n;
    cin>>n;
    while(n--){
        solve();
    }
}