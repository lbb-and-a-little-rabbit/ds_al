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
        vector<pair<int,pair<int,int>>> plat(n);
        for(int i=0;i<n;i++){
            cin >> plat[i].second.first >> plat[i].second.second >> plat[i].first;
        }
        sort(plat.begin(),plat.end());
        int nx,ny;
        cin >> nx >> ny;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(plat[i].first>ny){
                idx=i;
                break;
            }
        }
        int nowidx;
        if(idx==-1) nowidx=n-1;
        else if(idx==0){
            cout << nx << '\n';
            continue;
        }
        else nowidx=idx-1;
        while(ny&&nowidx>-1){
            ny=plat[nowidx].first;
            if(plat[nowidx].second.first<nx&&plat[nowidx].second.second>=nx){
                nx=plat[nowidx].second.second;
            }
            nowidx--;
        }
        cout << nx << '\n';
    }
}