#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

// using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;

int cnt[N];

std::vector<int> flipColor(std::vector<int> color, std::vector<int> t) {
	int n = color.size();
	std::vector<int> f(n, 0);

	memset(cnt, 0, sizeof cnt);

	for (int i : t)
		cnt[i]++;

	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
			f[i] = cnt[i];
		else
			f[i] = f[i - 1] + cnt[i];
	}

	std::vector<int> res;

	for(int i=0;i<n;++i){
		//std::cout << i <<  " ";
		if (f[i] % 2 == 0)
			res.pb(color[i]);
		else
			res.pb(color[i] == 1? 0 : 1);
	}

	return res;
}