#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt=0;
    vector<pair<int,int>> ans;
    int save=0;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        if(a%2==0){
            cnt+=a/2;
            for(int j=0;j<a/2;j++){
                ans.push_back({i,i});
            }
        }
        else{
            cnt+=a/2;
            for(int j=0;j<a/2;j++){
                ans.push_back({i,i});
            }
            if(save){
                ans.push_back({save,i});
                cnt++;
                save=0;
            }
            else{
                save=i;
            }
        }
    }
    if(save) cout << -1;
    else{
        cout << cnt << '\n';
        for(int i=0;i<ans.size();i++){
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
}