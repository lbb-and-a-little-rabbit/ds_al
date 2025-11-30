#include <bits/stdc++.h>

using namespace std;

class UnionFind{
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

public:
    UnionFind() {}

    int find(int x){
        if(!parent.count(x)){
            parent[x]=x;
            rank[x]=0;
        }
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        vector<pair<int,int>> ue;
        int x,y,e,n;
        cin >> n;
        UnionFind uf;
        for(int i=0;i<n;i++){
            cin >> x >> y >> e;
            if(e){
                uf.unite(x,y);
            }
            else{
                ue.push_back({x,y});
            }
        }
        bool valid=true;
        for(int i=0;i<ue.size();i++){
            auto [a,b]=ue[i];
            if(uf.connected(a,b)){
                valid=false;
                break;
            }
        }
        if(valid) cout << "YES\n";
        else cout << "NO\n";
    }
}