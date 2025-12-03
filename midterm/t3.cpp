#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using pii=pair<int,int>;

int n,a,b,c;
vector<pii> hs;
ld ans;

ld inline cal_d(int x,int y){
    return abs((ld)a*x+b*y+c)/sqrt(a*a+b*b);
}

pair<ld,ld> inline cal_co(int x,int y){
    ld rx=(ld)x-a*((ld)a*x+b*y+c)/(a*a+b*b);
    ld ry=(ld)y-b*((ld)a*x+b*y+c)/(a*a+b*b);
    return {rx,ry};
}

bool check(ld mid){
    pair<ld,ld> regin={-1.0,-1.0};
    int cnt=0;
    for(auto &[x,y]:hs){
        ld d=cal_d(x,y);
        auto [rx,ry]=cal_co(x,y);
        if(mid<d) return false;
        ld l=sqrt(mid*mid-d*d);
        ld lx=l*abs(b)/sqrt(a*a+b*b);
        ld x1=rx-lx,x2=rx+lx;
        if(cnt==0){
            regin.first=x1;
            regin.second=x2;
        }
        else{
            if(x2<regin.first) return false;
            if(x1>regin.second) return false;
            regin.first=max(regin.first,x1);
            regin.second=min(regin.second,x2);
        }
        cnt++;
    }
    return true;
}

bool check2(ld mid){
    pair<ld,ld> regin={-1.0,-1.0};
    int cnt=0;
    for(auto &[x,y]:hs){
        ld d=cal_d(x,y);
        auto [rx,ry]=cal_co(x,y);
        if(mid<d) return false;
        ld l=sqrt(mid*mid-d*d);
        ld y1=ry-l,y2=ry+l;
        if(cnt==0){
            regin.first=y1;
            regin.second=y2;
        }
        else{
            if(y2<regin.first) return false;
            if(y1>regin.second) return false;
            regin.first=max(regin.first,y1);
            regin.second=min(regin.second,y2);
        }
        cnt++;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ans=0.0;
        cin >> n;
        hs.resize(n);
        for(int i=0;i<n;i++){
            cin >> hs[i].first >> hs[i].second;
        }
        cin >> a >> b >> c;
        if(b){
            ld l=0,r=(ld)9e18;
            int cnt=0;
            while(l<r&&cnt<200){
                ld mid=l+(r-l)/2;
                bool valid=check(mid);
                if(valid){
                    ans=mid;
                    r=mid;
                }
                else{
                    l=mid;
                }
                cnt++;
            }
        }
        else{
            ld l=0,r=(ld)9e18;
            int cnt=0;
            while(l<r&&cnt<200){
                ld mid=l+(r-l)/2;
                bool valid=check2(mid);
                if(valid){
                    ans=mid;
                    r=mid;
                }
                else{
                    l=mid;
                }
                cnt++;
            }
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
}