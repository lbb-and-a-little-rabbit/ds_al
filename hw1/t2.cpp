#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<pair<string,string>> command;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    command.resize(n);
    for(int i=0;i<n;i++){
        cin >> command[i].first >> command[i].second;
    }
    deque<pair<string,string>> dq;
    for(int i=0;i<n;i++){
        dq.push_back(command[i]);
    }
    for(int i=0;i<dq.size();i++){
        if(dq[i].first=="echo"){
            cout << dq[i].second;
        }
        else{
            int m=stoi(dq[i].second);
            for(int j=0;j<m;j++){
                if(dq.size()<k){
                    dq.push_back(command[j]);
                }
                else break;
            }
        }
    }
}