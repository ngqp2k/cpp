#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 1e5;
int n, m, s, f;
vector< vector< pair<int, int> > > c;

class cmp{
	public:
	bool operator() (pair<int, int> a, pair<int, int> b){
		return a.se > b.se;
	}
};

void dijkstra(int start, int finish){
	vector<int> d(n + 1, INF); // d[i] la do dai ngan nhat tu start -> i
	vector<int> prev(n + 1); // danh dau duong di
	vector<bool> selected(n + 1, false);
	priority_queue< pair<int, int>, vector< pair<int, int> >, cmp > q;

	d[start] = 0;
	q.push(make_pair(start, d[start]));
	prev[start] = -1;

	while(q.empty() == false){
		auto p = q.top();
		q.pop();
		int u = p.fi;
		selected[u] = true;
		for(auto v: c[u]){
	    if (!selected[v.fi] && d[u] + v.se < d[v.fi]){ // cap nhat
				d[v.fi] = d[u] + v.se;
				prev[v.fi] = u;
				q.push(make_pair(v.fi, d[v.fi]));
			}
		}
	}

	cout << d[finish] << "\n";
	cout << finish;
	int i = prev[finish];
	while(i != -1){
		cout << " <- " << i;
		i = prev[i];
	}
}

void solve(){
	cin >> n >> m >> s >> f;
	c.resize(n + 1);
	for(int i=1;i<=m;++i){
		int u, v, val;
		cin >> u >> v >> val;
		c[u].push_back(make_pair(v, val));
		c[v].push_back(make_pair(u, val));
	}
	dijkstra(s, f);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
