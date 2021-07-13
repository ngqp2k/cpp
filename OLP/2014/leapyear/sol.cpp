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

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	int a, b; cin >> a >> b;	
	bool B[19];
	memset(B, false, sizeof B);
	B[0] = B[3] = B[6] = B[9] = B[11] = B[14] = B[17] = true;

	int cnt = 0;
	for(int i = a; i <= b; ++i)
		if (B[i % 19])
			cnt++;
	cout << cnt;
	return 0;
}
