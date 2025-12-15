#include <bits/stdc++.h>

using namespace std;

vector<int> c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;
    int m;
    while(cin >> m){
        c.push_back(m);
    }
    vector<int> dp(a+1,0);
    dp[0]=1;
    for(int coin:c){
        for(int i=coin;i<=a;i++){
            dp[i]+=dp[i-coin];
        }
    }
    cout << dp[a];
}