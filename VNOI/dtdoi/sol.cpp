#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9 + 7;
int a[111];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s; cin >> n >> s;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int x = *max_element(a + 1, a + n + 1);
  int ans = (s - x * x) / x;
  s -= ans * x;
  while (s > x * x) { s -= x, ans++; }
  vector<int> f(s + 10, INF);
  f[0] = 0;
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= s; ++i) {
    for(int j = 1; j <= n; ++j)
      if (i >= a[j])
        f[i] = min(f[i], f[i - a[j]] + 1);
      else
        break;
  }
  cout << ans + f[s] << "\n";
}

/*
  - Neu S > x * x (x la menh gia lon nhat)
  --> dung dung x (S -= x)

*/