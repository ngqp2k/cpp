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
template <class X, class Y> bool minimize(X &a, Y b) {
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b) {
    if (a < b) return a = b, true;
    return false;
}
 
void File()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASK".INP", "r",stdin);
    freopen(TASK".OUT", "w",stdout);
}
 
int n, minSz, diff;
int a[N];
int f_min[N][LOG + 1];
int f_max[N][LOG + 1];
 
void prepare(void) {
    for (int i = 1; i <= n; i ++) f_min[i][0] = f_max[i][0] = a[i];
    for (int j = 1; j <= LOG; j ++) for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
        f_min[i][j] = min(f_min[i][j - 1], f_min[i + (1 << (j - 1))][j - 1]);
        f_max[i][j] = max(f_max[i][j - 1], f_max[i + (1 << (j - 1))][j - 1]);
    }
}
 
bool check(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    int tmp_min = min(f_min[l][k], f_min[r - (1 << k) + 1][k]);
    int tmp_max = max(f_max[l][k], f_max[r - (1 << k) + 1][k]);
    return tmp_max - tmp_min > diff;
}
 
int dp[N];
void Solve(void) {
    cin >> n >> diff >> minSz;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    prepare();
 
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
 
    int l = 0;
    for (int r = minSz; r <= n; r ++) {
        while (r - l >= minSz && (check(l + 1, r) || dp[l] > INF)) l ++;
        if (r - l >= minSz) dp[r] = min(dp[r], dp[l] + 1);
    }
    cout << (dp[n] > INF ? -1 : dp[n]);
}
int main()
{
    File();
    int T = 1;
    // cin >> T;
    while (T --) {
        Solve();
    }
    return 0;
}