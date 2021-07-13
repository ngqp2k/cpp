#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

const int N = 101;

typedef pair<int, int> II;

vector< vector<int> > a, f;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

II st, en;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	a.resize(n + 2, vector<int> (m + 2, 1));
	f.resize(n + 2, vector<int> (m + 2, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char ch; cin >> ch;
			if (ch != '*')
				a[i][j] = 0;
			if (ch == 'B') st = II(i, j);
			if (ch == 'C') en = II(i, j);
		}
	queue<II> Q;
	// BFS - begin from st
	a[st.fi][st.se] = 1;
	Q.push(st);

	while (!Q.empty()) {
		int x = Q.front().fi;
		int y = Q.front().se;
		Q.pop();

		for (int i = 0; i < 4; ++i)
			if (a[x + dx[i]][y + dy[i]] == 0) {
				if (x + dx[i] == en.fi && y + dy[i] == en.se) {
					cout << f[x][y] + 1;
					return 0;
				}
				a[x + dx[i]][y + dy[i]] = 1;
				Q.push(II(x + dx[i], y + dy[i]));
				f[x + dx[i]][y + dy[i]] = f[x][y] + 1;
			}
	}
}
