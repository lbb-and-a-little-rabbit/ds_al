#include <bits/stdc++.h>

using namespace std;

class UnionFind{
    unordered_map<int,int> parent;

public:
    UnionFind(){}

    UnionFind(int n) : parent(n) {
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(parent.find(x)==parent.end()){
            parent[x]=x;
            return x;
        }
        if(parent[x]!=x){
            return find(parent[x]);
        }
        return x;
    }

    void unite(int a,int b){
        int roota=find(a);
        int rootb=find(b);
        if(roota!=rootb){
            parent[roota]=rootb;
        }
    }

    bool connected(int a,int b){
        return find(a)==find(b);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        UnionFind uf;
        vector<pair<int,int>> not_equal;
        for(int i=0;i<n;i++){
            int a,b,e;
            cin >> a >> b >> e;
            if(e==1) uf.unite(a,b);
            else not_equal.push_back({a,b});
        }
        int sz=not_equal.size();
        bool flag=true;
        for(int i=0;i<sz;i++){
            if(uf.connected(not_equal[i].first,not_equal[i].second)){
                cout << "NO\n";
                flag=false;
                break;
            }
        }
        if(flag) cout << "YES\n";
    }
}