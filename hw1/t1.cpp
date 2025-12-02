#include <bits/stdc++.h>

using namespace std;

int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<string> q;
    while(n--){
        int op;
        cin >> op;
        if(op==1){
            string id;
            cin >> id;
            if(q.size()<m) q.push(id);  
            else cout << "full\n";
        }
        else if(op==2){
            if(q.size()==0) cout << "empty\n";
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(op==3){
            cout << q.size() << '\n';
        }
    }
}