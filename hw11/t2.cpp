#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n,high;
ll ans;

bool must_use(ll sum,int bit){
    for(int i=high;i>=0;i--){
        if(i==bit) continue;
        bool allow=true;
        if(i>bit) allow=((ans>>i)&1);
        
        if(allow){
            ll cnt=sum>>i;
            if(cnt>n) cnt=n;
            sum-=(cnt<<i);
            if(sum==0) break;
        }
    }

    return sum!=0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int a;
        ll sum=0;
        for(int i=0;i<n;i++){
            cin >> a;
            sum+=a;
        }
        ans=0;
        high=(int)log2(sum)+1;
        for(int i=high;i>=0;i--){
            if(must_use(sum,i)){
                ans|=(1LL<<i);
            }
        }
        cout << ans << '\n';
    }
}