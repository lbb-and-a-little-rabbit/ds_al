#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll n;
ll ans=0;

class hash_map{
    vector<vector<ll>> bucket;
    ll sz;

public:
    ll node_sz;

    hash_map(ll n) : sz(n),bucket(n,vector<ll>()),node_sz(0) {}
    
    int hash_func(ll v){
        return (v%sz+sz)%sz;
    }

    void insert(ll v){
        int idx=hash_func(v);
        for(int i=0;i<bucket[idx].size();i++){
            if(bucket[idx][i]==v) return;
        }
        bucket[idx].push_back(v);
        node_sz++;
    }

    void find(ll v){
        int idx=hash_func(v);
        for(int i=0;i<bucket[idx].size();i++){
            if(bucket[idx][i]==v) ans++;
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ans=0;
        cin >> n;
        hash_map hm(n*2000);
        for(int i=0;i<n;i++){
            string op;
            ll tem;
            cin >> op >> tem;
            if(op=="insert"){
                for(int j=1;j<=1000;j++){
                    hm.insert(j*tem);
                }
            }
            else{
                hm.find(tem);
            }
        }
        cout << hm.node_sz << ' ' << ans  << '\n';
    }
}