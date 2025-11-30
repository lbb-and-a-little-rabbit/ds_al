#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;

int n,m;
vector<vector<pair<int,ld>>> adj;
ld ans=0.0;

void inline add(int u,int v,ld w){
    adj[u].push_back({v,w});
}

ld dist(int x1,int x2,int y1,int y2){
    return (ld)sqrt(((ld)x1-x2)*((ld)x1-x2)+((ld)y1-y2)*((ld)y1-y2));
}

void PrimeMST(){
    vector<char> inMst(n+m+1,false);
    vector<ld> minEdge(n+m+1,numeric_limits<ld>::max());
    int start=1;
    priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> pq;
    minEdge[start]=0;
    pq.push({0,start});
    int cnt=0;

    while(!pq.empty()&&cnt<m+n){
        auto [w,u]=pq.top();
        pq.pop();

        if(inMst[u]) continue;
        inMst[u]=true;
        cnt++;
        ans+=w;

        for(auto &[v,wt]:adj[u]){
            if(wt<minEdge[v]){
                minEdge[v]=wt;
                pq.push({wt,v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    adj.assign(n+m+1,{});
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(i-1>=0){
            add(i+1,i,dist(a[i],a[i-1],0,0));
        }
        if(i+1<n){
            add(i+1,i+2,dist(a[i],a[i+1],0,0));
        }
    }
    for(int i=0;i<m;i++){
        if(i-1>=0){
            add(n+i+1,n+i,dist(b[i],b[i-1],b[i],b[i-1]));
        }
        if(i+1<m){
            add(n+i+1,n+i+2,dist(b[i],b[i+1],b[i],b[i+1]));
        }
    }

    for(int i=0;i<n;i++){
        ld t=(ld)a[i]/2.0;
        auto it=lower_bound(b.begin(),b.end(),t);
        int idx=it-b.begin();
        for(int k=idx-1;k<=idx+1;k++){
            if(k>=0&&k<m){
                ld distance=dist(b[k],a[i],b[k],0);
                add(i+1,n+k+1,distance);
                add(n+k+1,i+1,distance);
            }
        }
    }

    for(int i=0;i<m;i++){
        ld t=(ld)b[i]/2.0;
        auto it=lower_bound(a.begin(),a.end(),t);
        int idx=it-a.begin();
        for(int k=idx-1;k<=idx+1;k++){
            if(k>=0&&k<n){
                ld distance=dist(b[i],a[k],b[i],0);
                add(n+i+1,k+1,distance);
                add(k+1,n+i+1,distance);
            }
        }
    }

    
    PrimeMST();
    cout << fixed << setprecision(10) << ans;
}