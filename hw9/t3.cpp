#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n,m;
ll ans=0;
vector<vector<int>> mat;
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
    for(int x=1;x<=t;x++){
        cin >> n >> m;
        mat.assign(n,vector<int>(m));
        adj.assign(n+m+1,{});
        indeg.assign(n+m+1,0);
        bool valid=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                if(mat[i][j]!=i+1&&mat[i][j]!=n+j+1){
                    valid=false;
                }
                if(mat[i][j]==i+1){
                    add(n+j+1,i+1);
                    indeg[i+1]++;
                }
                else{
                    add(i+1,n+j+1);
                    indeg[n+j+1]++;
                }
            }
        }
        if(!valid) continue;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<=n+m;i++){
            if(!indeg[i]) pq.push(i);
        }
        int cnt=0;
        while(!pq.empty()){
            int u=pq.top();
            pq.pop();
            cnt++;
            for(int v:adj[u]){
                if(--indeg[v]==0){
                    pq.push(v);
                }
            }
        }
        if(cnt==m+n) ans+=x;
    }
    cout << ans;
}