#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> dist;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        dist.assign(n,1e9);
        
        dist[src]=0;
        for(int i=1;i<=k+1;i++){
            bool updated=false;
            vector<int> last(n);
            for(int i=0;i<n;i++){
                last[i]=dist[i];
            }
            for(int i=0;i<flights.size();i++){
                int u=flights[i][0],v=flights[i][1],w=flights[i][2];
                if(last[u]+w<dist[v]){
                    dist[v]=last[u]+w;
                    updated=true;
                }
            }
            if(!updated) break;
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};