#include<bits/stdc++.h>
using namespace std;

int main() {
	int n = 30, m = 30;
	char ch[101][101];

    srand(time(NULL));
	freopen("in2", "w", stdout);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			int rd = rand() % 5;
			if (rd == 0)
				ch[i][j] = '*';
			else
				ch[i][j] = '.';
		}
	ch[1][1] = 'B';
	ch[29][28] = 'C';

	// print
	cout << n << " " << m << "\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << ch[i][j];
		cout << "\n";
	}
	return 0;
}