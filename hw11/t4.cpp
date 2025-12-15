#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n,m,w;
ll k;
vector<pair<int,char>> nv;

bool false_check(vector<int> &v,int block){
    int l=v.back()-k,r=v.back()-1;
    if(l<1||(l<=block&&r>=block)){
        cout << "-1\n";
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        bool val=true;
        cin >> n >> m >> k >> w;
        nv.resize(n+m+1);
        for(int i=0;i<n;i++){
            cin >> nv[i].first;
            nv[i].second=true;
        }
        for(int i=n;i<n+m;i++){
            cin >> nv[i].first;
            nv[i].second=false;
        }
        nv[n+m]={w+1,false};
        sort(nv.begin(),nv.end());
        stack<int> st;
        int block=0;
        for(auto [s,valid]:nv){
            if(valid){
                if(!st.empty()&&st.top()+k-1>=s) continue;
                st.push(s);
            }
            else{
                if(st.empty()||st.top()+k-1<s){
                    block=s;
                    continue;
                }
                else{
                    st.pop();
                    vector<int> v={s};
                    if(false_check(v,block)){
                        val=false;
                        break;
                    }
                    v.push_back(s-k);
                    while(!st.empty()&&st.top()+k-1>=v.back()){
                        if(false_check(v,block)){
                            val=false;
                            goto end;
                        }
                        v.push_back(v.back()-k);
                        st.pop();
                    }
                    for(int i=1;i<v.size();i++) st.push(v[i]);
                    block=s;
                }
            }
        }
end:
        if(val){
            cout << k*st.size() << '\n';
        }
    }
}