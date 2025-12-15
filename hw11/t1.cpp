#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n,m;
vector<int> a,b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        a.assign(n,0);
        b.assign(n,0);
        vector<int> d(n);
        ll asum=0,bsum=0;
        int delta=(m>=2*n-1)?n:(m-n);
        int atleast_mul=n-delta;
        for(int i=0;i<n;i++){
            cin >> a[i] >> b[i];
            asum+=a[i];
            bsum+=b[i];
            d[i]=b[i]-a[i];
        }
        if(!delta){
            cout << asum << '\n';
            continue;
        }
        if(n==1){
            cout << b[0] << '\n';
            continue;
        }
        sort(d.begin(),d.end());
        int cnt=0;
        ll benefit;
        while(cnt<atleast_mul){
            if(cnt==0){
                benefit=-d[0]-d[1];
                cnt+=2;
            }
            else{
                benefit=-d[cnt];
                cnt++;
            }
            bsum+=benefit;
        }
        while(cnt<n){
            if(cnt==0){
                benefit=-d[0]-d[1];
                cnt+=2;
            }
            else{
                benefit=-d[cnt];
                cnt++;
            }
            if(benefit>0) bsum+=benefit;
            else break;
        }
        cout << bsum << '\n';
    }
}