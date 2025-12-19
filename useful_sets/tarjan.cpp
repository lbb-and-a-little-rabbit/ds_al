#include <bits/stdc++.h>

using namespace std;

class Tarjan{
    int n;
    vector<vector<int>> adj,dag;
    vector<int> dfn,low,SccId;
    vector<char> Instack;
    stack<int> st;
    int Scc_cnt;
    int timeStamp;

public:
    Tarjan(int n_) : n(n_),Scc_cnt(0),timeStamp(0) {
        adj.assign(n,{});
        dfn.assign(n,0);
        low.assign(n,0);
        SccId.assign(n,-1);
        Instack.assign(n,false);
    }

    void add(int u,int v){
        adj[u].push_back(v);
    }

    void dfs(int u){
        dfn[u]=low[u]=++timeStamp;
        st.push(u);
        Instack[u]=true;

        for(int v:adj[u]){
            if(!dfn[v]){
                dfs(v);
                low[u]=min(low[u],low[v]);
            }
            else if(Instack[v]){
                low[u]=min(low[u],dfn[v]);
            }
        }

        if(low[u]==dfn[u]){
            while(true){
                int v=st.top();
                st.pop();
                Instack[v]=false;
                SccId[v]=Scc_cnt;
                if(v==u) break;
            }
            Scc_cnt++;
        }
    }

    void run(){
        for(int i=0;i<n;i++){
            if(!dfn[i]) dfs(i);
        }
    }

    void DAG_generate(){
        dag.assign(Scc_cnt,{});
        for(int u=0;u<n;u++){
            for(int v:adj[u]){
                if(SccId[u]!=SccId[v]){
                    dag[SccId[u]].push_back(SccId[v]);
                }
            }
        }
        for(int i=0;i<Scc_cnt;i++){
            sort(dag[i].begin(),dag[i].end());
            dag[i].erase(unique(dag[i].begin(),dag[i].end()),dag[i].end());
        }
    }

    bool hasCycle(){
        vector<int> sz(Scc_cnt,0);
        for(int u=0;u<n;u++){
            sz[SccId[u]]++;
        }
        for(int i=0;i<Scc_cnt;i++){
            if(sz[i]>=2) return true;
        }
        for(int u=0;u<n;u++){
            for(int v:adj[u]){
                if(u==v) return true;
            }
        }
        return false;
    }
};