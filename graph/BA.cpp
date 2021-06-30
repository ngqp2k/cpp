#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7

using namespace std;

const int mxN = 1e5;

typedef pair<int, int> II;

int n, m;
vector<vector<int>> g;

struct DfsTree{
	vector<int> num, low, parent;
	vector<bool> joi;
	int cnt, root, child;

	vector<int> cut;
	vector<II> bri;

	DfsTree(): num(n, -1), low(n, 0), joi(n, false), parent(n, 0), cnt(0), child(0){
		for(int i=0;i<n;++i)
			if (num[i] == -1){
				root = i, child = 0;
				dfs(i);
				joi[i] = (child > 1);
			}
		for(int i=0;i<n;++i)
			if (joi[i])
				cut.pb(i + 1);
	};
private:
	void dfs(int u){
		num[u] = low[u] = cnt++;
		for(int v: g[u]){
			if (num[v] == -1){
				parent[v] = u;
				if (u == root)
					child++;
				dfs(v);
				if (low[v] > num[u])
					bri.pb(II(u + 1, v + 1));
				if (low[v] >= num[u])
					joi[u] = true;
				low[u] = min(low[u], low[v]);
			}
			else {
				if (v != parent[u])
				  low[u] = min(low[u], num[v]);
			}
		}
	}

};

void solve(){
	cin >> n >> m;
	g.resize(n);
	for(int i=0;i<m;++i){
		int u, v; cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	DfsTree tt;
	// cout << "Brigde: ";
	// for(auto x: tt.bri)
	//   cout << x.fi << " " << x.se << "   ";
	// cout << "\n";
	// cout << "Cut point: ";
	// for(int x: tt.cut)
	//   cout << x << " ";
	cout << tt.cut.size() << " " << tt.bri.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
