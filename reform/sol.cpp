#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 2e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

// typedef long long int;
typedef pair<int, int> II;

int n, m;
int num[N], low[N], f[N];
int timeDfs = 0, sc = 0, ans = 0;
bool vis[N];

vector<int> g[N];
int bridges;
vector<int> part[N];

void dfs_1(int u) {
	if (vis[u]) return;
	vis[u] = true;
	part[sc].pb(u);
	for (int v : g[u])
		dfs_1(v);
}

void dfs_2(int u, int pre) {
	num[u] = low[u] = ++timeDfs;
	for (int v : g[u]) {
		if (v == pre) continue;
		if (num[v] == 0) {
			dfs_2(v, u);
			f[u] += f[v];
			if (low[v] > num[u]){
				bridges++;
				ans += f[v] * (n - f[v]) - 1;
			}
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	FO(1);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			sc++;
			dfs_1(i);
		}
	if (sc > 2) {
		cout << 0;
		exit(0);
	}
	for (int i = 1; i <= n; ++i)
		f[i] = 1;

	for (int i = 1; i <= n; ++i)
		if (num[i] == 0) {
			dfs_2(i, i);
		}
	if (sc == 2) {
		cout << (m - bridges) * part[1].size() * part[2].size();
		return 0;
	}
	int sumEdge = n * (n - 1) / 2;
	ans += (m - bridges) * (sumEdge - m);
	cout << ans;
	return 0;
}