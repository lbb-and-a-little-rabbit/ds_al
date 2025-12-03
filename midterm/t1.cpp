#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n,m,rx,ry;
vector<string> mp;
vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};

ll calculate(ll x,ll y,char op){
    if(op=='+') return x+y;
    if(op=='-') return abs(x-y);
    if(op=='*') return x*y;
    if(op=='/') return max(x,y)/min(x,y);
    return 0;
}

ll dfs(int x,int y,int from,char symbol){
    if(from==0) from=3;
    else if(from==1) from=2;
    else if(from==2) from=1;
    else if(from==3) from=0;

    if(symbol=='P'){
        for(int i=0;i<4;i++){
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&i!=from&&mp[dx][dy]!='.'){
                if(mp[dx][dy]=='#')
                    return dfs(dx,dy,i,'P');
                else
                    return dfs(dx,dy,i,mp[dx][dy]);
            }
        }
    }
    else if(!(symbol>='0'&&symbol<='9')){
        int cnt=0;
        vector<ll> save;
        for(int i=0;i<4;i++){
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&i!=from&&mp[dx][dy]!='.'&&mp[dx][dy]!='P'&&cnt<2){
                if(mp[dx][dy]=='#'){
                    save.push_back(dfs(dx,dy,i,symbol));
                    cnt++;
                }
                else{
                    save.push_back(dfs(dx,dy,i,mp[dx][dy]));
                    cnt++;
                }
            }
        }
        if(cnt==1){
                return save[0]; 
            }
        else{
            return calculate(save[0],save[1],symbol);
        }       
    }
    else{
        return symbol-'0';
    }
    return 0;
}

int main(){
    cin >> n >> m;
    mp.resize(n);
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='P'){
                rx=i;
                ry=j;
                goto DFS;
            }
        }
    }
DFS:
    cout << dfs(rx,ry,114514,'P');
}