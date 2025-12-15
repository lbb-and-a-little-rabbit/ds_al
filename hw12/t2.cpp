#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> dp(n,vector<int>(n,numeric_limits<int>::max()/2));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        dp[u][v]=dp[v][u]=1;
    }
    for(int z=0;z<n;z++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dp[i][j]=0;
                else{
                    dp[i][j]=min(dp[i][j],dp[i][z]+dp[z][j]);     
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        ll sum=0;
        for(int j=0;j<n;j++){
            sum+=dp[i][j];
        }
        cout << sum << ' ';
    }
}