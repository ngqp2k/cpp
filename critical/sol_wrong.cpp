#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

vector< vector<int> > g;
int n, m;

void File() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("in2", "r", stdin);
	freopen("ou2", "w", stdout);
}

vector<int> low, num, f, parent;
vector<bool> joint;
int timeDfs = 0, child = 0;

void dfs(int u, int pre) {
	num[u] = low[u] = ++timeDfs;
	for (int v : g[u]) {
		if (!num[v]) {
			if (u == pre) child++;
			parent[v] = u;
			dfs(v, u);
			f[u] += f[v];
			if (low[v] >= num[u]) {
				joint[u] = true;
				// ans += (f[v])
			}
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

int main() {
	File();
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	joint.resize(n + 1, false);
	low.resize(n + 1, 0);
	num.resize(n + 1, 0);
	parent.resize(n + 1, 0);
	f.resize(n + 1, 1);
	for (int i = 1; i <= n; ++i)
		if (!num[i]){
			child = 0;
			dfs(i, i);
			joint[i] = child > 1;
		}
	double ans = 0.0;
	for(int i=1;i<=n;++i)
		if (joint[i]){
			for(int j: g[i])
				if (parent[j] == i && low[j] >= num[i]){
					ans += ((f[j] * (n - f[j] - 1)) * 1.0 / n);
				}
		}
	cout << ans;
	return 0;
}