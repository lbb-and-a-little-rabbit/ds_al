#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> a;
    ll m;
    ll sum=0;
    while(cin >> m){
        a.push_back(m);
        sum+=m;
    }
    if(sum%2==1){
        cout << 0;
        return 0;
    }
    int n=a.size();
    ll target=sum/2;
    vector<char> dp(target+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++){
        for (ll j=target;j>=a[i];j--){
            if(dp[j-a[i]]){
                dp[j]=true;
            }
        }
        if(dp[target]){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}
