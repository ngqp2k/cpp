#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 1e3;

int n;
int a[mxN + 1];
int res = 0;

int hara(int u, int v, int d){
	if (u > v)
	  return 0;
	int j = u;
	for(int i=u;i<=v;++i)
		if (a[i] < a[j]){
			j = i;
		}
	if (a[j] <= d)
		return 0 + hara(u, j - 1, a[j]) + hara(j + 1, v, a[j]);
	else
	  return 1 + hara(u, j - 1, a[j]) + hara(j + 1, v, a[j]);
}

void solve(){
	cin >> n;
	int minArr = INF;
	int minj;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	cout << hara(1, n, 0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
