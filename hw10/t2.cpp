#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll INF=9e18;
int n,m,ans=0;
vector<vector<pair<int,int>>> adj;

void inline add(int u,int v,int w){
    adj[u].push_back({v,w});
}

bool spfa(int start){
    vector<ll> g(n+1,INF);
    vector<char> instack(n+1,false);
    vector<int> cnt(n+1,0);
    stack<int> st;

    g[start]=0;
    st.push(start);
    instack[start]=true;

    while(!st.empty()){
        int u=st.top();
        st.pop();
        instack[u]=false;

        for(auto &[v,w]:adj[u]){
            if(g[u]+w<g[v]){
                g[v]=g[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n) return true;
                if(!instack[v]){
                    st.push(v);
                    instack[v]=true;
                }
            }
        }
    }
    return false;
}

//队列写法：
bool spfa2(int start){
    vector<ll> g(n+1,INF);
    vector<char> inq(n+1,false);
    vector<int> cnt(n+1,0);
    queue<int> q;

    g[start]=0;
    q.push(start);
    inq[start]=true;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;

        for(auto &[v,w]:adj[u]){
            if(g[u]+w<g[v]){
                g[v]=g[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n) return true;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    return false;
}

bool Bellman_Ford(int start){
    vector<ll> g(n+1,INF);
    g[start]=0;

    for(int i=1;i<=n-1;i++){
        bool update=false;
        for(int u=1;u<=n;u++){
            for(auto &[v,w]:adj[u]){
                if(g[u]<INF&&g[u]+w<g[v]){
                    g[v]=g[u]+w;
                    update=true;
                }
            }
        }
        if(!update) break;
    }

    for(int u=1;u<=n;u++){
        for(auto &[v,w]:adj[u]){
            if(g[u]<INF&&g[u]+w<g[v]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.assign(n+1,{});
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
    }
    for(int i=1;i<=n;i++){
        if(spfa(i)) ans++;
    }
    cout << ans;
}