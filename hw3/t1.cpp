#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sz=0;
    string command;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> vec;
    vec.push_back(0);
    while(cin >> command){
        if(command=="push"){
            int x;
            cin >> x;
            vec.push_back(x);
            pq.push({x,vec.size()-1});
            sz++;
        }
        else if(command=="pop"){
            while(true){
                auto [x,idx]=pq.top();
                if(x==vec[idx]) break;
                pq.pop();
            }
            pq.pop();
            sz--;
        }
        else if(command=="top"){
            while(true){
                auto [x,idx]=pq.top();
                if(x==vec[idx]) break;
                pq.pop();
            }
            cout << pq.top().first << '\n';
        }
        else if(command=="size"){
            cout << sz << '\n';
        }
        else if(command=="decrease"){
            int i,k;
            cin >> i >> k;
            vec[i]=k;
            pq.push({k,i});
        }
    }
}