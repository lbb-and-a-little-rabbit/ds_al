#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    int x=0;
    int m,n;
    cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int idx=0;
    for(int i=0;i<n;i++){
        x++;
        while(idx<b[i]){
            if(!pq2.size()){
                pq1.push(a[idx++]);
            }
            else{
                int bigger=pq2.top();
                if(a[idx]>bigger){
                    pq2.push(a[idx++]);
                }
                else{
                    pq1.push(a[idx++]);
                }
            }
        }
        while(pq1.size()>x){
            int tem=pq1.top();
            pq1.pop();
            pq2.push(tem);
        }
        while(pq1.size()<x){
            int tem=pq2.top();
            pq2.pop();
            pq1.push(tem);
        }
        cout << pq1.top() << '\n';
    }
}