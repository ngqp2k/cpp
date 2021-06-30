// LCA
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7

using namespace std;

const int mxN = 1e5;
const int LOG = 20;

typedef pair<int, int> II;
vector<int> g[mxN];
int h[mxN], par[mxN], p[mxN][LOG];
bool slt[mxN];
int n, m, root, nr, H = 0;

void print();

void bfs(int root){
	queue<int> q;
	q.push(root);
	h[root] = 0;
	par[root] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		slt[u] = true;
		for(int v: g[u]){
			if (!slt[v]){
				par[v] = u;
				h[v] = h[u] + 1;
				H = max(H, h[v]);
				q.push(v);
			}
		}
	}
}

void init(){
	for(int i=1; i<=n; ++i)
		for(int j=0; j < LOG; ++j)
			p[i][j] = -1;

		for(int i=1;i<=n;++i)
			p[i][0] = par[i];

		for(int j=1; (1 << j) <= n; ++j)
			for(int i=1; i <= n; ++i) 
				if (p[i][j - 1] != -1)
					p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA(int u, int v){
	if (h[u] < h[v])
		swap(u, v);

	for(int j = LOG - 1; j >= 0; --j)
		if(h[p[u][j]] >= h[v] && p[u][j] != -1)
			u = p[u][j];

		if (u == v)
			return u;

		for(int j = LOG - 1; j >= 0; --j)
			if (p[u][j] != p[v][j] && p[u][j] != -1 && p[v][j] != -1){
				u = p[u][j];
				v = p[v][j];
			}
	return p[u][0];
}

void solve(){
	cin >> n >> m;
	for(int i=0;i<m;++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
	}
	memset(h, 0, sizeof(h));
	memset(slt, false, sizeof(slt));
	root = 1; 
	bfs(root);
	init();
	int q; cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		cout << LCA(x, y) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	cout << "\nDone\n";
	return 0;
}
