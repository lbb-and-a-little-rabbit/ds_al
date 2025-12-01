#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<pair<int,int>> se;
    while(n--){
        char op;
        cin >> op;
        if(op=='A'){
            int l,r;
            cin >> l >> r;
            int cnt=0;
            while(true){
                auto it=se.lower_bound({l,0});
                if(it==se.end()) break;
                if(it->first<=r){
                    se.erase(*it);
                    cnt++;
                }
                else break;
            }
            while(true){
                auto it=se.lower_bound({l,r});
                if(it==se.begin()) break;
                --it;
                if(it->second>=l){
                    se.erase(*it);
                    cnt++;
                }
                else break;
            }
            se.insert({l,r});
            cout << cnt << '\n';
        }
        else{
            cout << se.size() << '\n';
        }
    }
}