#include <bits/stdc++.h>

using namespace std;

class UnionFind{
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n): parent(n),rank(n,0) {
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy) return;
        if(rank[fx]<rank[fy]) parent[fx]=fy;
        else if(rank[fx]>rank[fy]) parent[fy]=fx;
        else{
            parent[fy]=fx;
            rank[fx]++;
        }
    }

    bool connected(int x,int y){
        return find(x)==find(y);
    }
};

int n,m;
vector<vector<pair<int,int>>> adj;
vector<char> vis;
vector<int> parent;
vector<int> parentw;
vector<int> path;
bool findC=false;

void add(int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void dfs(int u,int p){
    vis[u]=true;

    for(auto &[v,w]:adj[u]){
        if(v==p) continue;
        if(vis[v]){
            findC=true;
            path.push_back(w);
            for(int cur=u;cur!=v;cur=parent[cur]){
                path.push_back(parentw[cur]);
            }
            return;
        }
        else{
            parent[v]=u;
            parentw[v]=w;
            dfs(v,u);
            if(findC) return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        path.clear();
        adj.assign(n+1,{});
        vis.assign(n+1,false);
        parent.assign(n+1,-1);
        parentw.assign(n+1,0);
        UnionFind uf(n+1);
        findC=false;
        bool find=false;
        for(int i=1;i<=m;i++){
            int u,v;
            cin >> u >> v;
            if(!find){
                add(u,v,i);
                if(uf.connected(u,v)){
                    find=true;
                    dfs(u,-1);
                }
                else{
                    uf.unite(u,v);
                }
            }
        }
        if(!find){
            cout << "-1\n";
            continue;
        }
        sort(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout << path[i] << ' ';
        }
        cout << '\n';
    }
}