#include <bits/stdc++.h>

using namespace std;
using ui=unsigned int;
using ull=unsigned long long;

ull mod=998244353;

template <class T>
void sort(vector<T> &a){
    static ui cnt[100000]={0};
    for(int i=0;i<a.size();i++){
        cnt[a[i]]++;
    }
    int idx=0;
    for(int i=0;i<100000;i++){
        while(cnt[i]){
            a[idx]=i;
            cnt[i]--;
            idx++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,seed;
    cin >> n >> seed;
    mt19937 mt(seed);
    vector<ui> a(n);
    for(int i=0;i<n;i++){
        a[i]=mt()%100000;
    }
    sort(a);
    ull fra=100000;
    ull ans=0;
    for(int i=0;i<n;i++){
        ans+=(a[i]*fra)%mod;
        fra*=100000;
        fra%=mod;
        ans%=mod;
    }
    cout << ans%mod;
}