#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n,k;
vector<int> l,r;
vector<ll> w;

ll dfs(int root){
    if(!root) return 0;
    ll sum=dfs(l[root])+dfs(r[root])+w[root];
    if(sum==k) sum=0;
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int root;
        l.assign(n+1,0);
        r.assign(n+1,0);
        w.assign(n+1,0);
        vector<bool> isroot(n+1,true);
        for(int i=1;i<=n;i++){
            cin >> l[i] >> r[i];
            isroot[l[i]]=isroot[r[i]]=false;
        }
        for(int i=1;i<=n;i++){
            cin >> w[i];
        }
        for(int i=1;i<=n;i++){
            if(isroot[i]){
                root=i;
                break;
            }
        }

        ll res=dfs(root);
        if(res==0) cout << "YES\n";
        else cout << "NO\n";
    }
}