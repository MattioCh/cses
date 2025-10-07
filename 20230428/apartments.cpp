#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

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

vector<int> list;



int main() {
	// setIO("div7");
    int n,m,k;
	cin>>n>>m>>k;
	vi people, house;
	forn(i,1,n){
		int val;
		cin>>val;
		people.pb(val);
	}

	forn(i, 1, m){
		int val;
		cin>>val;
		house.pb(val);
	}

	sort(people.begin(), people.end(), greater<int>());
	sort(house.begin(), house.end(), greater<int>());
	int i=0, j=0, count=0;
	while(i<n && j<m){
		if(abs(people[i] - house[j]) <= k){
			count++;
			j++;
			i++;
		}else{
			if(people[i] > house[j]){
				i++;
			}else{
				j++;
			}
		}
	}

	cout<<count<<endl;
	
}