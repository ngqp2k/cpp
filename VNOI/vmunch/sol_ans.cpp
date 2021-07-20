#include<bits/stdc++.h>
#define MAX 111

using namespace std;

typedef pair<int, int> ii;

int c[MAX][MAX];
int l[MAX][MAX];
int m, n;
ii s, e;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void init(void) {
	scanf("%d", &m);
	scanf("%d", &n);
	int i, j;
	char t[MAX];
	for (i = 0; i <= m + 1; i = i + 1) {
		c[i][0] = 2;
		c[i][n + 1] = 2;
	}
	for (i = 0; i <= n + 1; i = i + 1) {
		c[0][i] = 2;
		c[m + 1][i] = 2;
	}
	for (i = 1; i <= m; i = i + 1)
		for (j = 1; j <= n; j = j + 1) {
			c[i][j] = 0;
			l[i][j] = 0;
		}
	for (i = 1; i <= m; i = i + 1) {
		scanf("%s", t);
		for (j = 1; j <= n; j = j + 1)
		{
			if (t[j - 1] == '*') c[i][j] = 2;
			if (t[j - 1] == 'B') s = ii(i, j);
			if (t[j - 1] == 'C') e = ii(i, j);
		}
	}
}
void bfs(void) {
	queue<ii> q;
	c[s.first][s.second] = 1;
	ii t;
	int i, x, y;
	q.push(s);
	while (!q.empty())
	{
		t = q.front(); q.pop();
		x = t.first;
		y = t.second;
		if (t == e)
		{
			printf("%d", l[x][y]);
			return;
		}
		for (i = 0; i < 4; i = i + 1)
			if (c[x + dx[i]][y + dy[i]] == 0) {
				c[x + dx[i]][y + dy[i]] = 1;
				l[x + dx[i]][y + dy[i]] = l[x][y] + 1;
				q.push(ii(x + dx[i], y + dy[i]));
			}
	}
}
int main(void) {
	init();
	bfs();
}