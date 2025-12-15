#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> m(n);
        vector<char> vis(n,false);
        for(int i=0;i<n;i++){
            cin >> m[i];
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                for(int j=i+1;j<n;j++){
                    if(m[j]==m[i]) vis[j]=true;
                    else if(m[j]<m[i]) break;
                }
                ans++;
            }
        }
        cout << ans << '\n';
    }
}