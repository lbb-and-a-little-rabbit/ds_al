#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=double;
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

ld dist(ld x1,ld x2,ld y1,ld y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

ld cal_D(ld x,ld y){
    ld res=numeric_limits<ld>::min();
    for(auto &[x0,y0]:hs){
        res=max(res,dist(x,x0,y,y0));
    }
    return res;
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
        int minx=numeric_limits<int>::max();
        int miny=numeric_limits<int>::max();
        int maxx=numeric_limits<int>::min();
        int maxy=numeric_limits<int>::min();
        for(int i=0;i<n;i++){
            cin >> hs[i].first >> hs[i].second;
            maxx=max(maxx,hs[i].first);
            maxy=max(maxy,hs[i].first);
            minx=min(minx,hs[i].second);
            miny=min(miny,hs[i].second);
        }
        cin >> a >> b >> c;
        if(b){
            ld l=(ld)minx-1e5,r=(ld)maxx+1e5;
            for(int i=0;i<200;i++){
                ld x1=l+(r-l)/3;
                ld x2=r-(r-l)/3;
                ld y1,y2;
                if(a==0){
                    y1=y2=-(ld)c/b;
                }
                else{
                    y1=(-(ld)c-a*x1)/b;
                    y2=(-(ld)c-a*x2)/b;
                }
                ld d1=cal_D(x1,y1);
                ld d2=cal_D(x2,y2);
                if(d1<d2){
                    r=x2;
                }
                else{
                    l=x1;
                }
                if(i==199) ans=min(d1,d2);
            }
        }
        else{
            ld l=(ld)miny-1e5,r=(ld)maxy+1e5;
            for(int i=0;i<200;i++){
                ld y1=l+(r-l)/3;
                ld y2=r-(r-l)/3;
                ld x1,x2;
                x1=x2=-(ld)c/a;
                ld d1=cal_D(x1,y1);
                ld d2=cal_D(x2,y2);
                if(d1<d2){
                    r=y2;
                }
                else{
                    l=y1;
                }
                if(i==199) ans=min(d1,d2);
            }
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
}