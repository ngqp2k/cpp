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
int e[2 * mxN + 1], l[2 * mxN + 1], h[mxN], depth[mxN], p[mxN][LOG];
int n, m, root;
int index = 1;

void print();

void dfs(int u){
	if (h[u] == 0)
		h[u] = index;
	e[index] = u;
	l[index++] = depth[u];
	for(int v: g[u]){
		depth[v] = depth[u] + 1;
		dfs(v);
		e[index] = u;
		l[index++] = depth[u];
	}
}

void init_SpareTable(){
	for(int i = 1; i < index; ++i)
		p[i][0] = i;

	for(int j = 1; (1 << j) < index; ++j)
		for(int i = 1; i + (1 << j) - 1 < index; ++i){
			if (l[p[i][j - 1]] <= l[p[i + (1 << (j - 1))][j - 1]])
			  p[i][j] = p[i][j - 1];
				else
				p[i][j] = p[i + (1 << (j - 1))][j - 1];
		}

}

int RMQ_L(int u, int v){
	if (u > v)
		swap(u, v);
	int k = v - u + 1;
	for(int j = LOG - 1; j >= 0; --j)
		if ((1 << j) <= k){
			if (l[p[u][j]] <= l[p[v - (1 << j) + 1][j]])
				return p[u][j];
			else
				return p[v - (1 << j) + 1][j];
		}
}

void test(){
	// int j = 2;
	// for(int i = 1; i < index; ++i)
		// cout << p[i][j] << " ";
	// cout << p[10][2] << " ";
}


int LCA(int u, int v){
	return e[RMQ_L(h[u], h[v])];
};

void solve(){
	cin >> n >> m;
	for(int i=0;i<m;++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
	}
	memset(h, 0, sizeof(h));
	root = 1;
 	depth[root] = 0;
	dfs(root);
	init_SpareTable();
	// test();
	// print();
	int q; cin >> q;
	while(q--){
		int u, v; cin >> u >> v;
		cout << LCA(u, v) << "\n";
	}
	// cout << RMQ(10, 15) << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	cout << "\nDone\n";
	return 0;
}

void print(){
	;
}
