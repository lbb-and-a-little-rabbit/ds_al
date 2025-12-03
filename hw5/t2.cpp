#include <iostream>
#include <vector>

using namespace std;

int inline ask(int u,int v){
    cout << "? " << u << ' ' << v << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void inline answer(int ans){
    cout << "! " << ans << endl;
    cout.flush();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt=0;
        int edge[2],non_edge[2];
        for(int i=1;i+1<=n;i+=2){
            if(ask(i,i+1)) {cnt++;edge[0]=i,edge[1]=i+1;}
            else {non_edge[0]=i,non_edge[1]=i+1;}
        }
        if(n%2==1){
            if(ask(n,1)) {cnt++;edge[0]=n,edge[1]=1;}
            else {non_edge[0]=n,non_edge[1]=1;}
        }
        if(cnt==0||cnt>=2){
            answer(1);
            continue;
        }
        int u=edge[0],v=edge[1],a=non_edge[0],b=non_edge[1];
        int connect;
        cnt=0;
        if(ask(u,a)){cnt++;connect=u;}
        if(ask(v,a)){cnt++;connect=v;}
        if(cnt==1){
            if(ask(connect,b)) answer(2);
            else answer(1);
        }
        else{
            answer(1);
        }
    }
}