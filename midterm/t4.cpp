#include <bits/stdc++.h>
using namespace std;

int gcd_int(int a, int b){
    if(b==0) return a;
    return std::gcd(a,b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    int LOG = 1;
    while((1<<LOG) <= n) LOG++;
    vector<int> lg2(n+1);
    for(int i=2;i<=n;i++) lg2[i] = lg2[i/2] + 1;

    // Sparse table for min and gcd
    vector<vector<int>> stMin(LOG, vector<int>(n+1));
    vector<vector<int>> stGcd(LOG, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        stMin[0][i] = a[i];
        stGcd[0][i] = a[i];
    }
    for(int k=1;k<LOG;k++){
        int len = 1 << k;
        int half = 1 << (k-1);
        for(int i=1;i + len - 1 <= n; i++){
            stMin[k][i] = min(stMin[k-1][i], stMin[k-1][i+half]);
            stGcd[k][i] = gcd_int(stGcd[k-1][i], stGcd[k-1][i+half]);
        }
    }

    auto getMin = [&](int L, int R)->int{
        int k = lg2[R-L+1];
        return min(stMin[k][L], stMin[k][R - (1<<k) + 1]);
    };
    auto getGcd = [&](int L, int R)->int{
        int k = lg2[R-L+1];
        return gcd_int(stGcd[k][L], stGcd[k][R - (1<<k) + 1]);
    };

    long long ans = 0;
    for(int l=1;l<=n;l++){
        int r = l;
        while(r <= n){
            int cur_g = getGcd(l, r);
            int cur_m = getMin(l, r);

            // 二分找到最远的 Rg 使 gcd(l, Rg) == cur_g
            int lo = r, hi = n, Rg = r;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(getGcd(l, mid) == cur_g){
                    Rg = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }

            // 二分找到最远的 Rm 使 min(l, Rm) == cur_m
            lo = r; hi = n;
            int Rm = r;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(getMin(l, mid) == cur_m){
                    Rm = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }

            int R = min(Rg, Rm);
            if(cur_g == cur_m){
                ans += (R - r + 1);
            }
            r = R + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
