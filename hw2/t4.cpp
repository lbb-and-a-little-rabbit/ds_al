#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using pii=pair<int,int>;
using ld=long double;

ld ans;

ld calR(ld a,vector<pii> &p,int n){
    ld R=-1.0;
    for(int i=0;i<n;i++){
        ld x=(ld)p[i].first,y=(ld)p[i].second;
        ld r=(a*a-2*x*a+x*x+y*y)/(2*y);
        R=max(R,r);
    }
    return R;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> points(n);
    bool neg=false,posi=false;
    int xmin=numeric_limits<int>::max(),xmax=numeric_limits<int>::min();
    for(int i=0;i<n;i++){
        cin >> points[i].first >> points[i].second;
        if(points[i].second>0) posi=true;
        if(points[i].second<0) neg=true;
        xmin=min(xmin,points[i].first);
        xmax=max(xmax,points[i].first);
    }
    if(posi&&neg){
        cout << -1;
        return 0;
    }
    if(neg){
        for(int i=1;i<=n;i++){
            points[i].second=-points[i].second;
        }
    }
    ld l=(ld)xmin-1e6L,r=(ld)xmax+1e6L;
    for(int i=0;i<200;i++){
        ld a1=l+(r-l)/3;
        ld a2=r-(r-l)/3;
        ld r1=calR(a1,points,n);
        ld r2=calR(a2,points,n);
        if(r1<r2){
            r=a2;
        }
        else{
            l=a1;
        }
        if(i==199){
            ans=min(r1,r2);
        }
    }
    cout << fixed << setprecision(10) << ans;
}