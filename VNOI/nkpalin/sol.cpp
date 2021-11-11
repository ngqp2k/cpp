#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
#define int long long
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<int, int> mi;

const int mxN = 2222;
int d[mxN][mxN];

void solve(int i, int j, int left, int right, string s, vector<char> &ans) {
    if (left > right)
        return;
    if (i == j) {
        ans[left] = s[i];
        //cout << left << " " << s[i] << " ";
    }
    else {
        if (s[i] == s[j]) {
            ans[left] = ans[right] = s[i];
            //cout << left << " " << right << " " << s[i] << " ";
            solve(i + 1, j - 1, left + 1, right - 1, s, ans);
        }
        else {
            if (d[i][j] == d[i + 1][j])
                solve(i + 1, j, left, right, s, ans);
            else
                solve(i, j - 1, left, right, s, ans);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.inp", "r", stdin);
    string s; cin >> s;
    int N = s.length();
    rep(i, N) rep(j, N) {
        d[i][i] = 1;
        d[i + 1][i] = 0;
    }
    for(int step = 1; step < N; ++step) {
        for(int i = 0; i < N - step; ++i) {
            int j = i + step;
            if (s[i] == s[j])
                d[i][j] = d[i + 1][j - 1] + 2;
            else
                d[i][j] = max(d[i + 1][j], d[i][j - 1]);
        }
    }

    vector<char> ans(d[0][N - 1]);
    solve(0, N - 1, 0, d[0][N - 1] - 1, s, ans);
    rep(i, d[0][N - 1])
        cout << ans[i];
}
