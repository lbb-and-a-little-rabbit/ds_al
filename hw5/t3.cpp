#include <iostream>
#include <vector>

using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

#define maxn 10000007

pll a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        sum+=a[i].second;
    }
    ll hf=sum/2;
    ll thf=sum/2;
    if(sum%2==1) thf++;
    ll l=0,r=n-1;
    while(l<=r){
        ll pivot=l+(r-l)/2;
        swap(a[r],a[pivot]);
        ll pos=l,lt=l;
        ll psum=0;
        for(int i=l;i<r;i++){
            if(a[i].first<a[r].first){
                swap(a[i],a[lt]);
                lt++;
                pos++;
            }
        }
        swap(a[r],a[pos]);
        for(int i=0;i<pos;i++){
            psum+=a[i].second;
        }
        if(psum<hf&&sum-psum-a[pos].second<=thf){
            cout << a[pos].first;
            break;
        }
        else if(psum>=hf) r=pos-1;
        else l=pos+1;
    }
}