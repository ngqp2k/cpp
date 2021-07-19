#include<bits/stdc++.h>
// #define int long long

using namespace std;

void updatePoint(vector<int> &f, int index, int val) {
	int i = index;
	while (i <= f.size()) {
		f[i] += val;
		i += i & (-i);
	}
}

void updateRange(vector<int> &f, int u, int v, int val) {
	updatePoint(f, u, val);
	updatePoint(f, v + 1, -val);
}

int get(vector<int> f, int index) { // get a[i]
	int sum = 0, i = index;
	while (i > 0) {
		sum += f[i];
		i -= i & (-i);
	}
	return sum;
}

int32_t main() {
	int n; cin >> n;
	vector<int> a(n + 1, 0), diff(n + 1, 0), ft(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i != 1)
			diff[i] = a[i] - a[i - 1];
		else
			diff[i] = a[i];
		updatePoint(ft, i, diff[i]);
	}
	;
	return 0;
}
