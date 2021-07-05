#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#define fi first
#define se second
#define pb push_back
//#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

vector<int> g[N];
int deg[N], depth[N];
bool vis[N];
bool ok;

void bfs(int root) {
	queue<int> qq;
	depth[root] = 1;
	qq.push(root);
	while (!qq.empty()) {
		int u = qq.front(); qq.pop();
		for (int v : g[u]) {
			if (!vis[v]) {
				depth[v] = depth[u] + 1;
				vis[v] = true;
				qq.push(v);
			}
			else {
				if ((depth[v] - depth[u] + 1) % 2 == 1)
					ok = false;
					// cout << "depth[" << v << "] depth[" << u << "] - 1\n";
			}
		}
	}
}

int spinachGardens(int n, std::vector<std::vector<int>> e){

	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 1; i <= n; ++i) vis[i] = false;
	for (int i = 1; i <= n; ++i) depth[i] = 0;

	int res = 0;
	vector<set<int>> tmp(n + 1);
	vector<int> deg(n + 1, 0);

	for (auto t : e) {
		tmp[t[0]].insert(t[1]);
		// deg[t[1]]++;
		// tmp[t[1]].insert(t[0]);
	}
	for (int i = 1; i <= n; ++i) {
		for (auto it : tmp[i]){
			g[i].push_back(it);
			deg[it]++;
		}
	}

	for(int i=1;i<=n;++i)
		cout << deg[i] << "\n";

	// for (int i = 1; i <= n; ++i) {
	// 	cout << i << ": ";
	// 	for (int j : g[i])
	// 		cout << j << " ";
	// 	cout << "\n";
	// }


	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			cout << "root" << i << "\n";
			ok = true;
			bfs(i);
			if (ok) res++;
		}

	return res;
}