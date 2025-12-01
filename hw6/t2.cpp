#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll x,y,v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    ll ans=0;
    unordered_map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin >> x >> v;
        if(v!=0){
            mp[v*x]++;
        }
    }
    for(int i=0;i<m;i++){
        cin >> y >> v;
        if(v!=0){
            ans+=mp[y*v];
        }
    }
    cout << ans;
}