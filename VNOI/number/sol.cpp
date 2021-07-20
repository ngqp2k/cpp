#include<bits/stdc++.h>
#define fi first
#define se second
// #define int long long
using namespace std;

const int N = 1e4 + 10; 

int n, m, t;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> t;
	vector<int> deg(n + 1, 0);
	for(int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		if (u != v) deg[u]++;
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if (i != t && deg[i] == 0)
			cnt++;
	cout << cnt;
	return 0;
}

