#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n,m;
ll ans=1;
ll mod=998244353;
vector<vector<int>> adj;
vector<char> vis;
vector<int> parent,depth;
map<pair<int,int>,bool> incycle;

void dfs(int u){
    vis[u]=true;

    for(int v:adj[u]){
        if(v==parent[u]) continue;
        if(vis[v]&&depth[v]<depth[u]){
            ll len=1;
            int x=min(u,v);
            int y=max(u,v);
            incycle[{x,y}]=true;
            for(int cur=u;cur!=v;cur=parent[cur]){
                len++;
                int miner=min(cur,parent[cur]);
                int maxer=max(cur,parent[cur]);
                incycle[{miner,maxer}]=true;
            }
            ans*=((1LL<<len)-1)%mod;
            ans%=mod;
        }
        else if(!vis[v]){
            parent[v]=u;
            depth[v]=depth[u]+1;
            dfs(v);
        }
    }
}

void inline add(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.assign(n+1,{});
    vis.assign(n+1,false);
    depth.assign(n+1,0);
    parent.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        add(u,v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int v:adj[i]){
            if(v<i&&!incycle[{v,i}]){
                ans=ans*2%mod;
            }
        }
    }
    cout << ans%mod;
}