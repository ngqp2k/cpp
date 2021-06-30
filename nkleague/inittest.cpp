#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define TASK ""

using namespace std;
const int N = 2e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

ofstream fo("nkleague\\input.inp");

void File(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


void solve() {
    srand(time(NULL));
	int n = rand() % 10 + 1;
	vector<vector<int>> a(n + 1, vector<int> (n + 1, 0));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < i; ++j){
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j] == 1 ? 0 : 1;
		}
	}
	fo << n << "\n";
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j)
			fo << a[i][j];
		fo << "\n";
	}
}

int main() {
  File();
  int T = 1;
  // cin >> T;
  while (T--) {
      solve();
  }
  fo.close();
  return 0;
}
