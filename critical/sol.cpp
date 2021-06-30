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
vector<int> num, low, cntV, par;
vector<bool> joint;
int timeDfs = 0, child = 0, k = 0;
int n, m;


void File() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("in1", "r", stdin);
	// freopen("ou1", "w", stdout);
}

vector<set<int>> part;
vector<int> trace;

void dfs(int u, int pre) {
	num[u] = low[u] = ++timeDfs;
	part[k].insert(u);
	trace[u] = k;
	for (int v : g[u]) {
		if (v == pre) continue;
		if (num[v] == 0) {
			if (u == pre) child++;
			par[v] = u;
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
	par.resize(n + 1, 0);
	low.resize(n + 1, 0);
	cntV.resize(n + 1, 1);
	joint.resize(n + 1, false);
	trace.resize(n + 1, 0);
	part.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		if (num[i] == 0) {
			k++;
			child = 0; par[i] = i;
			dfs(i, i);
			joint[i] = child > 1;
		}
	ll cnt = 0;
	vector<int> d;
	vector<bool> visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
		if (joint[i]) {
			int nn = part[trace[i]].size();
			d.clear();
			int sum = 0;
			for (int j : g[i])
				if (par[j] == i && low[j] >= num[i]) {
					d.pb(cntV[j]);
					sum += cntV[j];
				}
			d.pb(nn - sum - 1);
			// cout << i << "---\n";
			// for(int i: d)
			// 	cout << i << "\n";
			// cout << "\n";
			for (int i = 0; i < d.size() - 1; ++i)
				for (int j = i + 1; j < d.size(); ++j)
					cnt += d[i] * d[j];
			// cout << cnt << "\n";
		}
	double res = (double) cnt / (double) n * 1.0;
	cout << res;
}

int main() {
	File();
	solve();
	return 0;
}