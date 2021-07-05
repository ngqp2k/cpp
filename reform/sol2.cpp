#include <bits/stdc++.h>
using namespace std;
#define pb push_back
template <class T> void minn(T &A,T B) {A=min(A,B);}
typedef long long ll;
ll n,m,u,v,number[100005],low[100005],con[100005];
ll tplt=0,cau=0,res=0,j=0;
ll ans=0;
vector<ll> a[100005];
void DFS(ll u,ll parent)
{
    con[u] = 1;
    if(tplt==1)res++;
    low[u] = number[u] = ++j;
    for(ll v : a[u]){
        if(v==parent)continue;
        if(number[v])minn(low[u],number[v]);
        else{
            DFS(v,u);
            con[u] += con[v];
            minn(low[u],low[v]);
            if(low[v]>=number[v]){
                cau++;
                ans += con[v]*(n-con[v])-1;
            }
        }
    }

}
void init()
{
    cin >> n >> m;
    for(int i = 1;i <= m;++i){
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for(int i = 1;i <= n;++i){
        if(number[i]==0){
            tplt++;
            DFS(i,-1);
        }
    }
    if(tplt>2){
        cout << 0;
        exit(0);
    }
    if(tplt==2){
        cout <<(m-cau)*res*(n-res);
        exit(0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    ans+=(m-cau)*(n*(n-1)/2-m);
    cout << ans;
}