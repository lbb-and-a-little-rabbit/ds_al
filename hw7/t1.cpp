#include <bits/stdc++.h>

using namespace std;

vector<int> fa;

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

void connect(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    fa[fx]=fy;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        fa.assign(26,0);
        for(int i=0;i<26;i++){
            fa[i]=i;
        }
        for(int i=0;i<s1.size();i++){
            connect(s1[i]-'a',s2[i]-'a');
        }
        bool valid=false;
        for(int i=0;i<s1.size();i++){
            if(!(find(s1[i]-'a')==find(s3[i]-'a'))){
                valid=true;
                break;
            }
        }
        if(valid) cout << "YES\n";
        else cout << "NO\n";
    }
}