#include <bits/stdc++.h>

using namespace std;

int n,q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> q;
        deque<int> dq;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            dq.push_back(a);
        }
        for(int z=0;z<q;z++){
            int k;
            cin >> k;
            vector<int> save;
            for(int i=0;i<k;i+=2){
                dq.pop_front();
                save.push_back(dq[0]);
                dq.pop_front();
            }
            for(int i=0;i<save.size();i++){
                dq.push_front(save[i]);
            }
        }
        for(int i=0;i<dq.size();i++){
            cout << dq[i] << ' ';
        }
        cout << '\n';
    }
}