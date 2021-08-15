#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 6666;

int N, L;
int w[mxN], dp[mxN], f[mxN];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in", "r", stdin);
  // freopen("ou", "w", stdout);
  cin >> N >> L;
  f[0] = 0;
  for(int i = 1; i <= N; ++i) {
    cin >> w[i];
  }
  dp[0] = 0;
  for(int i = 1; i <= N; ++i) {
    dp[i] = mxN;
    int j = i, curSum = w[i];
    while (j > 0 && curSum <= L) {
      dp[i] = min(dp[i], max(dp[j - 1], L - curSum));
      curSum += w[--j];
    }
  }
  cout << dp[N];
}