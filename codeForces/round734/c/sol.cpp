#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10;

typedef pair<int, int> II;
vector<II> d;


void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	d.resize(n);
	int maxx = 0, pos;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		d[i].fi = a[i];
		d[i].se = i;
	}

	sort(d.begin(), d.end());
	vector<bool> b(n + 10, false);
	vector<int> dd(n + 10, 0), ans(n, 0), cnt(n + 1, 0);
	int tt = 1;
	for (int i = 0; i < n; ++i) {
		if (dd[d[i].fi] >= k)
			ans[d[i].se] = 0;
		else {
			dd[d[i].fi]++;
			ans[d[i].se] = tt;
			cnt[tt]++;
			++tt;
			if (tt > k) {
				tt = 1;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i)
		cout << ans[i] << " ";
	bool ok = true;
	for(int i = 1; i < k; ++i)
		if (cnt[i] != cnt[i + 1])
			ok = false;
	if (ok)
		cout << 0;
	else
		cout << ans[n - 1];
	cout << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}

