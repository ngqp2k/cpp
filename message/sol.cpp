#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int n, m;
vector<int> g[N];
int num[N], low[N], scc[N];
bool vis[N], del[N];

int timeDfs = 0, cntScc = 0, part = 0;

stack<int> S;

void dfs(int u) {
	num[u] = low[u] = ++timeDfs;
	S.push(u);
	for (int v : g[u])
		if (!del[v]) {
			if (num[v] == 0) {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else
				low[u] = min(low[u], num[v]);
		}
	if (low[u] == num[u]) {
		cntScc++;
		int v;
		do {
			v = S.top(), S.pop(), del[v] = true;
			scc[v] = cntScc;
		} while (v != u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
		if (num[i] == 0) {
			part++;
			dfs(i);
		}
	// init new graph
	vector<int> deg(n + 1, 0);
	vector< vector<int> > h(n + 1);

	int ans = cntScc;

	for (int i = 1; i <= n; ++i)
		for (int j : g[i])
			if (scc[i] != scc[j])
				if (!deg[scc[j]]) {
					deg[scc[j]]++;
					ans--;
				}
	cout << ans;
}

