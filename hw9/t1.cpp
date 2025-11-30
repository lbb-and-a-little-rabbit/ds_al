#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> indeg;

void inline add(int u,int v){
    adj[u].push_back(v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        adj.assign(n+1,{});
        indeg.assign(n+1,0);
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            add(u,v);
            indeg[v]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<=n;i++){
            if(!indeg[i]) pq.push(i);
        }
        while(!pq.empty()){
            int u=pq.top();
            pq.pop();
            cout << u << ' ';
            for(int v:adj[u]){
                if(--indeg[v]==0){
                    pq.push(v);
                }
            }
        }
        cout << '\n';
    }
}