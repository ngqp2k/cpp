#include<iostream>
using namespace std;
int A[101];

int main(){
    freopen("DAYSO.INP","r",stdin);
    //freopen("DAYSO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>A[i];
    }
    cout<<n<<endl;
   for(int i=1;i<=n;i++) cout<<A[i]<<" ";
    return 0;
}