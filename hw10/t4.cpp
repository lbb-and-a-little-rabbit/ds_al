#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int t,m,a0,a1,a2,a3;
int goal=15;
vector<vector<pair<int,int>>> adj;
ll INF=9e18;
ll dist[16][16];
ll dp[1<<16][16];

void inline add(int u,int v,int w){
    adj[u].push_back({v,w});
}

void Dijkstra(int start){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<char> vis(16,false);
    dist[start][start]=0;
    pq.push({dist[start][start],start});

    while(!pq.empty()){
        auto [wt,u]=pq.top();
        pq.pop();

        if(vis[u]) continue;
        vis[u]=true;

        for(auto &[v,w]:adj[u]){
            if(dist[start][u]+w<dist[start][v]){
                dist[start][v]=dist[start][u]+w;
                pq.push({dist[start][v],v});
            }
        }
    }
}

int change(int u, int a, int b = -1, int c = -1, int d = -1) {
    int mask = 0;
    if (a >= 0) mask |= (1 << a);
    if (b >= 0) mask |= (1 << b);
    if (c >= 0) mask |= (1 << c);
    if (d >= 0) mask |= (1 << d);
    return u ^ mask;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> a0 >> a1 >> a2 >> a3;
    adj.assign(16,{});
    for(int u=0;u<=15;u++){
        for(int i=0;i<4;i++){
            add(u,change(u,i),a0);
        }
        add(u,change(u,0,1),a1);
        add(u,change(u,2,3),a1);
        add(u,change(u,0,2),a2);
        add(u,change(u,1,3),a2);
        add(u,change(u,0,1,2,3),a3);
    }

    while(t--){
        cin >> m;
        vector<int> mset(m,0);
        for(int i=0;i<m;i++){
            for(int j=3;j>=0;j-=2){
                int bit;
                cin >> bit;
                int a=bit/10,b=bit%10;
                mset[i]+=(a<<j);
                mset[i]+=(b<<(j-1));
            }
        }
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                dist[i][j]=INF;
            }
        }
        for(int i=0;i<16;i++){
            Dijkstra(i);
        }
        vector<int> req(m);
        for(int i=0;i<m;i++){
            req[i]=mset[i]^goal;
        }
        vector<int> req2idx(16,-1);
        for(int i=0;i<m;i++){
            req2idx[req[i]]=i;
        }
        int all_achieve=(1<<m)-1;
        for(int i=0;i<(1<<m);i++){
            for(int j=0;j<16;j++){
                dp[i][j]=INF;
            }
        }
        int initmask=0;
        if(req2idx[0]!=-1) initmask|=(1<<req2idx[0]);
        dp[initmask][0]=0;

        for(int i=0;i<(1<<m);i++){
            for(int u=0;u<16;u++){
                if(dp[i][u]==INF) continue;
                for(int v=0;v<16;v++){
                    int newmask=i;
                    if(req2idx[v]!=-1) newmask|=(1<<req2idx[v]);
                    dp[newmask][v]=min(dp[newmask][v],dp[i][u]+dist[u][v]);
                }
            }
        }
        ll ans=INF;
        for(int i=0;i<16;i++){
            ans=min(ans,dp[all_achieve][i]);
        }
        cout << ans << '\n';
    }
}