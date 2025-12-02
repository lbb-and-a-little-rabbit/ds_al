#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll ans=0;
int n;

void merge(vector<int> &a,int l,int r){
    int mid=l+(r-l)/2;
    vector<int> L,R;
    for(int i=l;i<=mid;i++){
        L.push_back(a[i]);
    }
    for(int i=mid+1;i<=r;i++){
        R.push_back(a[i]);
    }
    int n1=L.size(),n2=R.size(),i1=0,i2=0;
    while(i1<n1&&i2<n2){
        if(L[i1]<R[i2]){
            a[l+i1+i2]=L[i1];
            i1++;
        }
        else{
            a[l+i1+i2]=R[i2];
            i2++;
            ans+=(n1-i1);
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

void merge_sort(vector<int> &a,int l,int r){
    if(l>=r) return;
    int mid=l+(r-l)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    merge(a,l,r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ans=0;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        merge_sort(a,0,n-1);
        cout << ans << '\n';
    }
}