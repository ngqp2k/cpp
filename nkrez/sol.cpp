#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 30000 + 10;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	int n; cin >> n;
	II Q[N];
	vector<int> en[N];
	for(int i = 1; i <= n; ++i) {
		cin >> Q[i].fi >> Q[i].se;
		en[Q[i].se].pb(i);
	}
	int f[N];
	f[0] = 0;
	for(int i = 1; i <= 30000; ++i) {
		f[i] = f[i - 1];
		for(int j: en[i])
			f[i] = max(f[i], f[Q[j].fi] + Q[j].se - Q[j].fi);
	}
	cout << f[30000];
	return 0;
}
