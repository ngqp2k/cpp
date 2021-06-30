#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
const int N = 2e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

vector< vector<int> > g;
vector<int> num, low, cntV;
vector<bool> joint;
int timeDfs = 0, child = 0;
int n, m;


void File() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("in2", "r", stdin);
	freopen("ou2", "w", stdout);
}

void dfs(int u, int pre) {
	num[u] = low[u] = ++timeDfs;
	for (int v : g[u]) {
		if (v == pre) continue;
		if (num[v] == 0) {
			if (u == pre) child++;
			dfs(v, u);
			cntV[u] += cntV[v];
			if (low[v] >= num[u]) {
				joint[u] = true;
			}
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}


void solve() {
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	num.resize(n + 1, 0);
	low.resize(n + 1, 0);
	cntV.resize(n + 1, 1);
	joint.resize(n + 1, false);
	for (int i = 1; i <= n; ++i)
		if (num[i] == 0) {
			child = 0;
			dfs(i, i);
			joint[i] = child > 1;
		}
	for (int i = 1; i <= n; ++i)
		if (joint[i])
			cout << i << " ";
}

int main() {
	File();
	solve();
	return 0;
}