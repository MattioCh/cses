#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>


using namespace std;


#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll MOD = 7;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}



int main() {
	// setIO("div7");
    int n;
    cin>>n;
    vi arr;
    forn(i, 0,n-1){
        ll val;cin>>val;
        arr.pb(val);
    }

    sort(arr.begin(), arr.end());

    ll median = arr[n / 2], ans=0;
	for (auto x : arr) {
		ans += abs(median - x);  // Calculate the cost to modify the stick	                         // length
	}
	cout << ans << endl;
    
}