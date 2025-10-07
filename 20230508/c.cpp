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

    int arr[n];
    forn(i, 0,n-1){
        cin>>arr[i];
    }

    sort(arr, arr+n, greater<int>());
    
    set<int> seats_taken;
    int count =0;
    forn(i , 0, n-1){
        if(arr[i] > 0 && seats_taken.find(arr[i]) != seats_taken.end()){
            seats_taken.insert(arr[i]);
            count++;
        }else if(arr[i] == -1){
            auto it = seats_taken.lower_bound(arr[i]);
            
            if(it == seats_taken.end()){
                seats_taken.insert(arr[i]);
                count++;
            }
            else if(seats_taken.find((*it -1)) != seats_taken.end()){
                seats_taken.insert(*it -1);
                count++;
            }else if(seats_taken.find(1) != seats_taken.end()){
                seats_taken.insert(1);
                count++;
            }
        }else if(arr[i]==-2){
            auto it =seats_taken.upper_bound(arr[i]);
            
            if(it == seats_taken.end()){
                seats_taken.insert(arr[i]);
                count++;
            }
            else if(seats_taken.find((*it + 1)) != seats_taken.end()){
                seats_taken.insert(*it +1);
                count++;
            }
            else if(seats_taken.find(m) != seats_taken.end()){
                seats_taken.insert(m);
                count++;
            }
        }

    }

    cout<<"HI"<<count<<endl;
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