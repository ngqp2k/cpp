#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

void solve(){
	int k; cin >> k;
	// 2 * n * m + n + m = 2 * k - 1
	int i = -1, j = -1, Min = INFLL;
	for(int n = 1; n <= (int) sqrt(2 * k); ++n) {
		if (((2 * k - 1) - n) % (2 * n + 1) == 0) {
			int m = ((2 * k - 1) - n) / (2 * n + 1);
			if (max(n, m) - min(n, m) < Min){
				i = min(n, m), j = max(n, m);
				Min = j - i;
			}
		}
	}
	cout << i << " " << j << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	int tt; cin >> tt;
	while(tt--) {
		solve();
	}
	return 0;
}
