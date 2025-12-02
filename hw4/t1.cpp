#include <bits/stdc++.h>

using namespace std;
using ull=unsigned long long;
using pui=pair<ull,int>;

void merge(vector<vector<char>> &cmp,vector<pui> &a,int l,int r){
    int mid=l+(r-l)/2;
    vector<pui> L,R;
    for(int i=l;i<=mid;i++){
        L.push_back(a[i]);
    }
    for(int i=mid+1;i<=r;i++){
        R.push_back(a[i]);
    }
    int n1=L.size(),n2=R.size(),i1=0,i2=0;
    while(i1<n1&&i2<n2){
        if(cmp[L[i1].second][R[i2].second]=='0'){
            cout << '?' << endl;
            cout << L[i1].first << ' ' << R[i2].first << endl;
            char res;
            cin >> res;
            if(res=='<'){
                cmp[L[i1].second][R[i2].second]='1';
                cmp[R[i2].second][L[i1].second]='2';
            }
            else{
                cmp[L[i1].second][R[i2].second]='2';
                cmp[R[i2].second][L[i1].second]='1';
            }
        }
        if(cmp[L[i1].second][R[i2].second]=='1'){
            a[l+i1+i2]=L[i1];
            i1++;
        }
        else{
            a[l+i1+i2]=R[i2];
            i2++;
        }
    }
    while(i1<n1){
        a[l+i1+i2]=L[i1];
        i1++;
    }
    while(i2<n2){
        a[l+i1+i2]=R[i2];
        i2++;
    }
}

void merge_sort(vector<vector<char>> &cmp,vector<pui> &a,int l,int r){
    if(l>=r) return;
    int mid=l+(r-l)/2;
    merge_sort(cmp,a,l,mid);
    merge_sort(cmp,a,mid+1,r);
    merge(cmp,a,l,r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pui> a(n);
        vector<vector<char>> cmp(n,vector<char>(n,'0'));
        for(int i=0;i<n;i++){
            cin >> a[i].first;
            a[i].second=i;
        }
        merge_sort(cmp,a,0,n-1);
        cout << '!' << endl;
        for(int i=0;i<n;i++){
            cout << a[i].first << ' ';
        }
        cout << endl;
    }
}