// LCA
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7

using namespace std;

const int mxN = 1e5;

typedef pair<int, int> II;
vector<int> g[mxN];
int h[mxN], parent[mxN], p[mxN];
bool slt[mxN];
int n, m, root, nr, H = 0;

void print();

void bfs(int root){
	queue<int> q;
	q.push(root);
	h[root] = 0;
	parent[root] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		slt[u] = true;
		for(int v: g[u]){
			if (!slt[v]){
				parent[v] = u;
				h[v] = h[u] + 1;
				H = max(H, h[v]);
				;
				q.push(v);
			}
		}
	}
}

void dfs(int node){
	if (slt[node])
		return;
	slt[node] = true;
	if (h[node] < nr)
		p[node] = root;
	else
		if (h[node] % nr == 0)
			p[node] = parent[node];
		else
			p[node] = p[parent[node]];
	for(int u: g[node])
		dfs(u);
}

void LCA(int u, int v){
	while(p[u] != p[v])
		if (h[u] > h[v])
			u = p[u];
		else
			v = p[v];
	
	if (h[u] < h[v])
		swap(u, v);

	while(u != v){
		if (h[u] > h[v])
			u = parent[u];
		else if (h[u] < h[v])
			v = parent[v];
		else{
			u = parent[u];
			v = parent[v];
		}
	}
	cout << u << "\n";
}

void solve(){
	int x, y;
	cin >> n >> m >> x >> y;
	for(int i=0;i<m;++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(h, 0, sizeof(h));
	memset(slt, false, sizeof(slt));
	root = 1; 
	bfs(root);
	nr = sqrt(H);
	// cout << nr;
	memset(slt, false, sizeof(slt));
	dfs(root);
	// print();
	LCA(x, y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	cout << "\nDone\n";
	return 0;
}

void print(){
	for(int i=1;i<=n;++i)
		cout << h[i] << " ";
	cout << "\n";
	for(int i=1;i<=n;++i)
		cout << parent[i] << " ";
	cout << "\n";
	for(int i=1;i<=n;++i)
		cout << p[i] << " ";
	cout << "\n";
}
