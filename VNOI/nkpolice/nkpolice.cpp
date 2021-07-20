#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
const int N = 1e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n, m, q;
vector<int> g[N + 1];
int low[N + 1], num[N + 1], tail[N + 1];
int p[N + 1][LOG + 1], depth[N + 1];
int timeDfs = 0, child = 0;
bool joint[N + 1];

void calcP(){
	p[1][0] = 1;
	for(int j = 1; j <= LOG; ++j)
		for(int i = 1; i <= n; ++i)
			p[i][j] = p[p[i][j - 1]][j - 1];
}

int find(int u, int v){
	for(int j = LOG; j >= 0; --j)
		if (depth[u] - depth[v] - 1 >= (1 << j))
			u = p[u][j];
	return u;
}

void dfs(int u, int pre){
	num[u] = low[u] = ++timeDfs;
	for(int v: g[u]){
		if (v == pre) continue;
		if (num[v] == 0){
			if (u == pre) child++;
			depth[v] = depth[u] + 1;
			p[v][0] = u;
			dfs(v, u);
			if (low[v] >= num[u])
				joint[u] = true;
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
	tail[u] = timeDfs;
}

bool check(int u, int root){
	return (num[root] <= num[u] && num[u] <= tail[root]);
}

bool sol1(int u, int v, int g1, int g2){
	if (num[g1] > num[g2])
		swap(g1, g2);
	if (low[g2] != num[g2]) return true;
	if (check(u, g2) && !check(v, g2)) return false;
	if (check(v, g2) && !check(u, g2)) return false;
	return true;
}

bool sol2(int u, int v, int k){
	if (!joint[k]) return true;
	int pu = 0, pv = 0;
	if (check(u, k)) pu = find(u, k);
	if (check(v, k)) pv = find(v, k);

	if (pu == pv) return true;
	if (!pv && low[pu] < num[k]) return true;
	if (!pu && low[pv] < num[k]) return true;
	if (pu && pv && low[pu] < num[k] && low[pv] < num[k]) return true;
	return false;
}

void test(){
	cout << find(13, 7) << "\n";
	cout << find(12, 7) << "\n";
	cout << find(6, 1) << "\n";
	return;
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(joint, false, sizeof joint);
	memset(num, 0, sizeof num);
	depth[1] = 1;
	dfs(1, 1);
	joint[1] = child > 1;
	calcP();
	cin >> q;
	while(q--){
		int chose; cin >> chose;
		if (chose == 1){
			int u, v, g1, g2; cin >> u >> v >> g1 >> g2;
			cout << (sol1(u, v, g1, g2) ? "yes\n" : "no\n");
		}
		else {
			int u, v, k; cin >> u >> v >> k;
			cout << (sol2(u, v, k) ? "yes\n" : "no\n");
		}
	}
}

int main() {
  ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}
