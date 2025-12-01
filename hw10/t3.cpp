#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;

struct Point{
    int x,y;
};

int n,v1,v2;
vector<vector<pair<int,ld>>> adj;
vector<char> vis;
vector<ld> g;
vector<Point> points;
ld maxv2dis;

void inline add(int u,int v,ld w){
    adj[u].push_back({v,w});
}

ld dist(Point a,Point b){
    return (ld)sqrt(((ld)a.x-b.x)*((ld)a.x-b.x)+((ld)a.y-b.y)*((ld)a.y-b.y));
}

ld Dijkstra(int start){
    priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> pq;
    g[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        auto [gw,u]=pq.top();
        pq.pop();

        if(vis[u]) continue;
        vis[u]=true;

        if(u==n+1){
            return gw;
        }

        for(auto &[v,w]:adj[u]){
            if(w+g[u]<g[v]){
                g[v]=w+g[u];
                pq.push({g[v],v});
            }
        }
    }
    return 0.0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.assign(n+2,{});
    vis.assign(n+2,false);
    g.assign(n+2,numeric_limits<ld>::max());
    points.resize(n+2);
    for(int i=1;i<=n;i++){
        cin >> points[i].x >> points[i].y;
    }
    cin >> points[0].x >> points[0].y >> points[n+1].x >> points[n+1].y;
    cin >> v1 >> v2;
    maxv2dis=(ld)v2*3;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n+1;j++){
            if(i==j) continue;
            ld w=0.0;
            if(i==0){
                w=dist(points[i],points[j])/(ld)v1;
            }
            else{
                ld dis=dist(points[i],points[j]);
                if(dis>maxv2dis){
                    w=3.0+(dis-maxv2dis)/(ld)v1;
                }
                else{
                    w=dis/(ld)v2;
                }
            }
            add(i,j,w);
        }
    }
    cout << fixed << setprecision(10) << Dijkstra(0);
}