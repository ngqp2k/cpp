#include<bits/stdc++.h>
#include "BridgeArticulation.h"
using namespace std;

int V;
vector< vector <int> > G;

int main() {
    int m;
    while (cin >> V >> m) {
        G.resize(V);
        while (m--) {
            int u, v; cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        UndirectedDfs tree;

        cout << "Bridges: ";
				for(int i=0;i<tree.bridges.size();++i)
					cout << 1+tree.bridges[i].first << " " << 1+tree.bridges[i].second << "  ";
        // REP(i,tree.bridges.size()) cout << 1+tree.bridges[i].first << ' ' << 1+tree.bridges[i].second << "   ";
        cout << endl;
        cout << "Cut points: ";
				for(int i=0;i<tree.cuts.size();++i)
					cout << 1 + tree.cuts[i] << " ";
        // REP(i,tree.cuts.size()) cout << 1+tree.cuts[i] << ' ';
        cout << endl;
    }
}
