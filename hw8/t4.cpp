#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> adj;
vector<char> vis;
vector<int> idx;

void inline add(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int ans=0;
        cin >> n >> m;
        adj.assign(n+1,{});
        vis.assign(n+1,false);
        idx.assign(n+1,0);
        vector<int> st;
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            if(u!=v) add(u,v);
        }
        for(auto &vec:adj){
            sort(vec.begin(),vec.end());
            vec.erase(unique(vec.begin(),vec.end()),vec.end());
        }
        vis[1]=true;
        st.push_back(1);
        for(int x=2;x<=n;x++){
            if(vis[x]) continue;
            while(true){
                if(st.empty()){
                    ans++;
                    vis[x]=true;
                    st.push_back(x);
                    break;
                }
                int v=st.back();
                while(idx[v]<adj[v].size()&&vis[adj[v][idx[v]]]) idx[v]++;
                if(idx[v]==adj[v].size()){
                    st.pop_back();
                    continue;
                }
                int nowv=adj[v][idx[v]];
                if(nowv==x){
                    st.push_back(x);
                    vis[x]=true;
                    idx[v]++;
                    break;
                }
                else{
                    ans++;
                    st.push_back(x);
                    vis[x]=true;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}