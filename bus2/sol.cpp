#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
//#define int long long
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
int a[N][N], dp[N][N], A[N * N];
vector<int> g[N];

int getId(int i, int j) {
	return (i - 1) * m + j;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			A[getId(i, j)] = a[i][j];
		}

	// init graph
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			int u = getId(i, j);
			g[u].pb(getId(i, j + 1));
			g[u].pb(getId(i + 1, j));
		}
	}

	for (int i = 1; i < m; ++i) {
		int u = getId(n, i);
		g[u].pb(getId(n, i + 1));
	}

	for (int i = 1; i < n; ++i) {
		int u = getId(i, m);
		g[u].pb(getId(i + 1, m));
	}

	vector<int> f(N * N, INF);

	f[1] = A[1] == 0 ? 1 : 0;

	queue<int> Q;
	Q.push(1);

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		bool ok = f[u] % 2 == 0; // ok = true - cac den giu nguyen
		bool ok2;
		if (ok)
			if (A[u] == 0)
				ok2 = false;
			else
				ok2 = true;
		else {
			if (A[u] == 0)
				ok2 = true;
			else
				ok2 = false;
		}

		for (int v : g[u]) {
			if (ok2)
				f[v] = min(f[v], f[u] + 1);
			else
				f[v] = min(f[v], f[u] + 2);
			Q.push(v);
		}
	}
	if (A[n * m] == 1) {
		if (f[n * m] % 2 == 1)
			cout << f[n * m] + 1;
		else
			cout << f[n * m] ;
	}
	else {
		if (f[n * m] % 2 == 1)
			cout << f[n * m];
		else
			cout << f[n * m] + 1;
	}
	return 0;
}
