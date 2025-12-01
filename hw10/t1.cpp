#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,p,seed;
    cin >> n >> seed >> p;
    std::mt19937 mt(seed);
    vector<bitset<2003>> mat(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) mat[i][j]=1;
            else{
                if(mt()%p==0) mat[i][j]=1;
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(mat[i][k]){
                mat[i]|=mat[k];
            }
        }
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
        cnt+=mat[i].count();
    }
    cout << cnt;
}