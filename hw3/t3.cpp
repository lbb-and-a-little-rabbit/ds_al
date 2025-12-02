#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<pll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second=1;
        pq.push({a[i].first,i});
    }
    for(int i=0;i<k;i++){
        while(true){
            auto [val,idx]=pq.top();
            if(a[idx].second==0||a[idx].first!=val) pq.pop();
            else break;
        }
        auto [val,idx]=pq.top();
        pq.pop();
        a[idx].second=0;
        for(int j=idx-1;j>=0;j--){
            if(a[j].second==1){
                a[j].first+=val;
                pq.push({a[j].first,j});
                break;
            }
        }
        for(int j=idx+1;j<n;j++){
            if(a[j].second==1){
                a[j].first+=val;
                pq.push({a[j].first,j});
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i].second==1){
            cout << a[i].first << ' ';
        }
    }
}