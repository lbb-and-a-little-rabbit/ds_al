#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll cross(vector<int> &a,int l,int r){
    int mid=l+(r-l)/2;
    ll lsum=0,rsum=0;
    ll lres=numeric_limits<ll>::min();
    ll rres=numeric_limits<ll>::min();
    for(int i=mid;i>=l;i--){
        lsum+=a[i];
        lres=max(lres,lsum);
    }
    for(int i=mid+1;i<=r;i++){
        rsum+=a[i];
        rres=max(rres,rsum);
    }
    return rres+lres;
}

ll solve(vector<int> &a,int l,int r){
    if(l>=r) return a[l];
    int mid=l+(r-l)/2;
    ll res1=solve(a,l,mid);
    ll res2=solve(a,mid+1,r);
    ll res3=cross(a,l,r);
    return max({res1,res2,res3});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << solve(a,0,n-1) << '\n';
    }
}