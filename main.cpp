#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

struct UnionFind {
  vector<int> d;
  UnionFind(int n = 0): d(n, -1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  UnionFind f(10);
  if (f.unite(1, 2)) {
    cout << "ok\n";
  }
  if (f.unite(1, 5)) {
    cout << "ok\n";
  }
  cout << f.same(2, 5) << "\n";
  cout << f.same(4, 5);
}