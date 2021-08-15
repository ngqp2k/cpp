#include <bits/stdc++.h>
using namespace std;

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rand() * 1LL * rand() % (h - l + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(time(NULL));
  freopen("in4.txt", "w", stdout);
  int n = 200, m = 200;
  cout << n << " " << m << "\n";
  cout << Rand(2, n) << " " << Rand(2, m) << "\n";
  cout << Rand(2, n) << " " << Rand(2, m) << "\n";
  for(int i = 1; i <= n; ++i) {
    for(int j = 1;j <= m; ++j) {
        cout << Rand(1, 30000) << " ";
    }
    cout << "\n";
  }
}