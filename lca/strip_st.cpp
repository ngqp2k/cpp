#include <bits/stdc++.h>
#define fi first
#define se second
#define TASK "STRIP"

using namespace std;
const int N = 2e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;

void File()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen(TASK".INP", "r", stdin);
  // freopen(TASK".OUT", "w", stdout);
}

int dp[N], a[N], ptMin[N][LOG], ptMax[N][LOG];
int n, minSz, diff;

void init_SpareTable() {
  for (int i = 1; i <= n; ++i)
    ptMin[i][0] = ptMax[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 1; i <= n; ++i) {
      ptMin[i][j] = min(ptMin[i][j - 1], ptMin[i + (1 << (j - 1))][j - 1]);
      ptMax[i][j] = max(ptMax[i][j - 1], ptMax[i + (1 << (j - 1))][j - 1]);
    }
}

bool check(int l, int r) {
  for (int j = LOG - 1; j >= 0; --j)
    if ((1 << j) <= (r - l + 1)) {
      int tmpMax = max(ptMax[l][j], ptMax[r - (1 << j) + 1][j]);
      int tmpMin = min(ptMin[l][j], ptMin[r - (1 << j) + 1][j]);
      return tmpMax - tmpMin > diff;
    }
}

void solve() {
  cin >> n >> diff >> minSz;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  init_SpareTable();

  memset(dp, 0x3f, sizeof(dp));
  int left = 0; dp[0] = 0;

  // dp[r] = min(dp[r], dp[l] + 1) ||     r - l >= minSz, check(l + 1, r) = false ||
  for (int right = minSz; right <= n; right++) {
    while ((right - left) >= minSz && (check(left + 1, right) || dp[left] > INF)) left++;
    if (right - left >= minSz) dp[right] = min(dp[right], dp[left] + 1);
  }

  if (dp[n] > INF)
    cout << -1;
  else
    cout << dp[n];

}

int main()
{
  File();
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
