#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int unsigned long long

using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

struct Matrix{
	int a11, a12, a21, a22;
	Matrix(int a, int b, int c, int d) { a11 = a, a12 = b, a21 = c, a22= d; }
};

Matrix multiMatrix(Matrix a, Matrix b) {
	int c11 = ((a.a11 % MOD * b.a11 % MOD) % MOD + (a.a12 % MOD * b.a21 % MOD) % MOD) % MOD;
	int c12 = ((a.a11 % MOD * b.a12 % MOD) % MOD + (a.a12 % MOD * b.a22 % MOD) % MOD) % MOD;
	int c21 = ((a.a21 % MOD * b.a11 % MOD) % MOD + (a.a22 % MOD * b.a21 % MOD) % MOD) % MOD;
	int c22 = ((a.a21 % MOD * b.a12 % MOD) % MOD + (a.a22 % MOD * b.a22 % MOD) % MOD) % MOD;

	return Matrix(c11, c12, c21, c22);
}

Matrix powMatrix(Matrix a, int n) {
	if (n == 1)
		return a;
	Matrix tmp = powMatrix(a, n / 2);
	if (n % 2 == 0)
		return multiMatrix(tmp, tmp);
	else
		return multiMatrix(multiMatrix(tmp, tmp), a);
}

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	int a1, n; cin >> a1 >> n;

	Matrix a = Matrix(0, 1, 1, 1);
	auto res = powMatrix(a, n - 1);

	int ans = (((res.a11 * a1 % MOD) % MOD + (res.a12 * a1 % MOD) % MOD + 
			(res.a21 * a1 % MOD) % MOD + (res.a22 * a1 % MOD) % MOD) % MOD - a1 % MOD + MOD) % MOD;
	cout << ans;
	return 0;
}
