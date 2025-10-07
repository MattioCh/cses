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
    int n, k;
    cin>>n>>k;
    map<int, int> s;
    int index = 0;
    while(n--){
        int a;
        cin>>a;
        if(s.find(a) != s.end()){
            cout<<s[a]+1<<" "<<index+1<<endl;
            return 0;
        }
        s.insert({k-a, index});
        index++;

    }
    
    cout<<"IMPOSSIBLE"<<endl;
	
}