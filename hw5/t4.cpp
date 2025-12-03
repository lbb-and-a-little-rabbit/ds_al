#include <bits/stdc++.h>
using namespace std;

vector<int> sz;
int n;

int dfs(int x,int p,vector<pair<int,int>> &sons,vector<int> &parent,vector<int> &deleted,vector<int> &fa){
    if(!x || deleted[x]) return 0;
    sz[x]=1;
    fa[x]=p;
    int l = sons[x].first, r = sons[x].second, pr = parent[x];
    if(l && l != p && !deleted[l]) sz[x]+=dfs(l,x,sons,parent,deleted,fa);
    if(r && r != p && !deleted[r]) sz[x]+=dfs(r,x,sons,parent,deleted,fa);
    if(pr && pr != p && !deleted[pr]) sz[x]+=dfs(pr,x,sons,parent,deleted,fa);
    return sz[x];
}

void del(int start,int block,int &remain,vector<pair<int,int>> &sons,vector<int> &parent,vector<int> &deleted){
    if(!start || deleted[start]) return;
    vector<pair<int,int>> stk;
    stk.emplace_back(start, block);
    while(!stk.empty()){
        auto cur = stk.back(); stk.pop_back();
        int u = cur.first, from = cur.second;
        if(!u || deleted[u]) continue;
        deleted[u]=1;
        remain--;
        int l = sons[u].first, r = sons[u].second, pr = parent[u];
        if(l && l != from && !deleted[l]) stk.emplace_back(l, u);
        if(r && r != from && !deleted[r]) stk.emplace_back(r, u);
        if(pr && pr != from && !deleted[pr]) stk.emplace_back(pr, u);
    }
};

int ask(int a,int b){
    cout << "? " << a << " " << b << endl;
    int tem;
    cin >> tem;
    return tem;
}

void answer(int x){
    cout << "! " << x << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int remain=n;
        vector<int> deleted(n+1,false);
        vector<pair<int,int>> sons(n+1);
        vector<bool> ischild(n+1,false);
        vector<int> parent(n+1,0);
        for(int i=1;i<=n;i++){
            int l,r;
            cin >> l >> r;
            sons[i]={l, r};
            ischild[l]=true;
            ischild[r]=true;
            if(l) parent[l]=i;
            if(r) parent[r]=i;
        }

        int root;
        for(int i=1;i<=n;i++){
            if(!ischild[i]) {
                root=i;
                break;
            }
        }
        sz.assign(n+1,0);
        vector<int> fa(n+1,0);

        while(remain>2){
            int half=remain/2;

            fill(sz.begin(), sz.end(), 0);

            int p=0;
            fa[root]=p;
            dfs(root,p,sons,parent,deleted,fa);


            int tgt=root;
            vector<int> selected(n+1,0);
            selected[tgt]=1;
            while(true){
                int heavy=0;
                int l=sons[tgt].first,r=sons[tgt].second,pr=parent[tgt];
                if(l&&!deleted[l]&&sz[l]>half&&!selected[l]) {heavy=l;selected[l]=1;}
                if(r&&!deleted[r]&&sz[r]>half&&!selected[r]) {heavy=r;selected[r]=1;}
                if(pr&&!deleted[pr]&&sz[pr]>half&&!selected[pr]) {heavy=pr;selected[pr]=1;}
                if(heavy) tgt=heavy;
                else break;
            }



            vector<pair<int,int>> vec;
            int f=fa[tgt];
            if(f!=0&&!deleted[f]){
                int up=remain-sz[tgt];
                vec.emplace_back(up,f);
            }
            int l=sons[tgt].first,r=sons[tgt].second,pr=parent[tgt];
            if(l&&l!=f&&!deleted[l]) vec.emplace_back(sz[l],l);
            if(r&&r!=f&&!deleted[r]) vec.emplace_back(sz[r],r);
            if(pr&&pr!=f&&pr!=l&&pr!=r&&!deleted[pr]) vec.emplace_back(sz[pr],pr);
            sort(vec.rbegin(),vec.rend());
            if(vec.size() <= 1){
                if(vec.empty()) continue;
                int nei=vec[0].second;
                int res=ask(tgt,nei);
                if(res==0){
                    del(nei,tgt,remain,sons,parent,deleted);
                    root=tgt;
                } 
                else{
                    del(tgt,nei,remain,sons,parent,deleted);
                    root=nei;
                }
            } 
            else {
                int y1=vec[0].second;
                int y2=vec[1].second;
                int res=ask(y1,y2);
                if(res==0){
                    for(auto &pr : vec){
                        int el=pr.second;
                        if(el!=y1) del(el,tgt,remain,sons,parent,deleted);
                    }
                    if(!deleted[tgt]){ 
                        deleted[tgt]=1;
                        remain--; 
                    }
                    root = y1;
                } 
                else if(res==2){
                    for(auto &pr:vec){
                        int el=pr.second;
                        if(el!=y2) del(el,tgt,remain,sons,parent,deleted);
                    }
                    if(!deleted[tgt]){ 
                        deleted[tgt]=1; 
                        remain--; 
                    }
                    root = y2;
                } 
                else {
                    del(y1,tgt,remain,sons,parent,deleted);
                    del(y2,tgt,remain,sons,parent,deleted);
                    root=tgt;
                }
            }
            if(root==0||deleted[root]){
                int nr=0;
                for(int i=1;i<=n;i++){ 
                    if(!deleted[i]){ 
                        nr=i;
                        break; 
                    }
                }
                if(nr==0) break;
                root=nr;
            }
        }
        if(remain==1){
            for(int i=1;i<=n;i++){
                if(!deleted[i]){
                    answer(i);
                    break;
                }
            }
        } 
        else{
            int u=0,v=0;
            for(int i=1;i<=n;i++){
                if(!deleted[i]){
                    if(u==0) u=i;
                    else v=i;
                }
            }
            if(u && v){
                int r = ask(u,v);
                if(r==0) answer(u);
                else answer(v);
            } 
            else if(u) answer(u);
        }
    }
}
