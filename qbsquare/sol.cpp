#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1000 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n, m;
int a[N][N], f[N][N];

int max1 = 0, max2 = 0;

void solve1() {
	memset(f, 0, sizeof f);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if (a[i][j] == 1) {
				// cout << i << " " << j << "\n";
				f[i][j] = 0;
				continue;
			}
			f[i][j] = 1;
			if (f[i][j - 1] != 0 && f[i - 1][j] != 0 && f[i - 1][j - 1] != 0) {
				f[i][j] = max(f[i][j], min(f[i][j - 1], min(f[i - 1][j], f[i - 1][j - 1])) + 1);
				max1 = max(max1, f[i][j]);
			}
		}
	}
}

void solve2() {
	memset(f, 0, sizeof f);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if (a[i][j] == 0) {
				// cout << i << " " << j << "\n";
				f[i][j] = 0;
				continue;
			}
			f[i][j] = 1;
			if (f[i][j - 1] != 0 && f[i - 1][j] != 0 && f[i - 1][j - 1] != 0) {
				f[i][j] = max(f[i][j], min(f[i][j - 1], min(f[i - 1][j], f[i - 1][j - 1])) + 1);
				max2 = max(max2, f[i][j]);
			}
		}
	}
}



int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	solve1();
	solve2();

	cout << max(max1, max(max2, (int)1));
	return 0;
}
