#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int n,q;
ll asum=0,msum=0;
priority_queue<pll,vector<pll>,greater<pll>> pq;
vector<ll> a,m; 

void solve(){
    if(msum==n){
        cout << "-1\n";
        return;
    }
    while(true){
        auto [val,idx]=pq.top();
        if(m[idx]!=val) pq.pop();
        else break;
    }
    auto [val,idx]=pq.top();
    if(m[idx]==1){
        ll cost=msum-n;
        cout << (asum-msum)/cost+1 << '\n';
        return;
    }
    int day=0;
    ll sum=asum;
    while(true){
        sum-=(msum-val);
        if(sum<val){
            cout << day << '\n';
            return;
        }
        else{
            sum/=val;
            sum+=(n-1);
            day++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    a.resize(n);
    m.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        asum+=a[i];
    }
    for(int i=0;i<n;i++){
        cin >> m[i];
        msum+=m[i];
        pq.push({m[i],i});
    }
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int i,x;
            cin >> i >> x;
            asum=asum-a[i-1]+x;
            a[i-1]=x;
        }
        else if(op==2){
            int i,x;
            cin >> i >> x;
            msum=msum-m[i-1]+x;
            m[i-1]=x;
            pq.push({x,i-1});
        }
        else if(op==3){
            solve();
        }
    }
}