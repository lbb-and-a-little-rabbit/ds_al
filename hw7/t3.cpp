#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> mat;
vector<int> spot;
vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};

int ans=1e9+1;

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

bool check(int mid){
    UnionFind uf(m*n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                int nx=i+dir[k][0],ny=j+dir[k][1];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&abs(mat[i][j]-mat[nx][ny])<=mid){
                    uf.unite(n*i+j,n*nx+ny);
                }
            }
        }
    }
    int fir=spot[0];
    for(int i=1;i<spot.size();i++){
        if(!uf.connected(fir,spot[i])){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    mat.assign(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    int tem;
    for(int i=0;i<m*n;i++){
        cin >> tem;
        if(tem) spot.push_back(i);
    }
    int l=0,r=1e9+1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
}