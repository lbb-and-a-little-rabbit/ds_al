#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>> &ans,int left,int right,int up,int down,int k,int mx,int my,int &code){
    if(k==1){
        for(int i=up;i<=down;i++){
            for(int j=left;j<=right;j++){
                if(!(i==mx&&j==my)){
                    ans[i][j]=code;
                }
            }
        }
        code++;
        return;
    }
    int len=right-left+1;
    int half=len/2;
    int ymid=left+half;
    int xmid=up+half;


    //poop mountains
    //1
    if(mx<xmid&&my<ymid){
        ans[xmid-1][ymid]=ans[xmid][ymid-1]=ans[xmid][ymid]=code;
        code++;
        solve(ans,left,ymid-1,up,xmid-1,k-1,mx,my,code);
        solve(ans,ymid,right,up,xmid-1,k-1,xmid-1,ymid,code);
        solve(ans,left,ymid-1,xmid,down,k-1,xmid,ymid-1,code);
        solve(ans,ymid,right,xmid,down,k-1,xmid,ymid,code);
    }
    //2
    if(mx<xmid&&my>=ymid){
        ans[xmid-1][ymid-1]=ans[xmid][ymid-1]=ans[xmid][ymid]=code;
        code++;
        solve(ans,left,ymid-1,up,xmid-1,k-1,xmid-1,ymid-1,code);
        solve(ans,ymid,right,up,xmid-1,k-1,mx,my,code);
        solve(ans,left,ymid-1,xmid,down,k-1,xmid,ymid-1,code);
        solve(ans,ymid,right,xmid,down,k-1,xmid,ymid,code);
    }
    //3
    if(mx>=xmid&&my<ymid){
        ans[xmid-1][ymid]=ans[xmid-1][ymid-1]=ans[xmid][ymid]=code;
        code++;
        solve(ans,left,ymid-1,up,xmid-1,k-1,xmid-1,ymid-1,code);
        solve(ans,ymid,right,up,xmid-1,k-1,xmid-1,ymid,code);
        solve(ans,left,ymid-1,xmid,down,k-1,mx,my,code);
        solve(ans,ymid,right,xmid,down,k-1,xmid,ymid,code);
    }
    //4
    if(mx>=xmid&&my>=ymid){
        ans[xmid-1][ymid]=ans[xmid][ymid-1]=ans[xmid-1][ymid-1]=code;
        code++;
        solve(ans,left,ymid-1,up,xmid-1,k-1,xmid-1,ymid-1,code);
        solve(ans,ymid,right,up,xmid-1,k-1,xmid-1,ymid,code);
        solve(ans,left,ymid-1,xmid,down,k-1,xmid,ymid-1,code);
        solve(ans,ymid,right,xmid,down,k-1,mx,my,code);
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k,x,y;
        int code=1;
        cin >> k >> x >> y;
        int size=(int)pow(2,k);
        vector<vector<int>> ans(size,vector<int>(size));
        solve(ans,0,size-1,0,size-1,k,x-1,y-1,code);
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}