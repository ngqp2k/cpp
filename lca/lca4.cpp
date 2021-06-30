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
int h[mxN], parent[mxN];
bool slt[mxN];
int n, m, root;

void print();

void LCA(int u, int v){
	;
}

void solve(){
	int x, y;
	cin >> n >> m;
	for(int i=0;i<m;++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
	}
	memset(h, 0, sizeof(h));
	memset(slt, false, sizeof(slt));
	root = 1;
	// print();
	// LCA(x, y);
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
}
