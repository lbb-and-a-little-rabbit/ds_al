#include <bits/stdc++.h>
using namespace std;

using ll=long long;

struct Edge{
    int u,v;
    ll w;
    bool operator < (const Edge& other) const{
        return w<other.w;
    }
};

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

vector<Edge> edges;
vector<vector<pair<int,ll>>> adj;
int l,r;
ll ans=0;

void add(int u,int v,ll w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

ll LCM(ll a,ll b){
    return a/std::gcd(a,b)*b;
}

void KruskalMst(){
    sort(edges.begin(),edges.end());
    UnionFind uf(r+1);
    for(auto &e:edges){
        if(!uf.connected(e.u,e.v)){
            uf.unite(e.u,e.v);
            ans+=e.w;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r;
    int n=r-l+1;
    adj.assign(r+1,{});
    for(int d=1;d<=r;d++){
        int k=(l+d-1)/d;
        int x=k*d;
        if (x>r) continue;
        for(int y=x+d;y<=r;y+=d) {
            edges.push_back({x,y,LCM(x,y)});
        }
    }
    KruskalMst();
    cout << ans << "\n";
    return 0;
}
