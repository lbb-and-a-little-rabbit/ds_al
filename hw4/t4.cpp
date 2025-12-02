#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> A,B;
    vector<string> ans;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        A.push(x);
    }

    for(int len=1;len<n;len*=2){
        int pos=0;
        while(pos<n){
            for(int i=pos;i<pos+len;i++){
                if(i<n){
                    int tem=A.front();
                    A.pop();
                    B.push(tem);
                    ans.push_back("A B\n");
                }
            }
            pos=pos+len;
            int n2=B.size();
            int n1;
            if(pos+len<n){
                n1=n2;
                pos+=len;
            }
            else{
                n1=n-pos;
                pos=n;
            }
            int i1=0,i2=0;
            while(i1<n1&&i2<n2&&n1!=0&&n2!=0){
                int a=A.front(),b=B.front();
                if(a<b){
                    A.pop();
                    A.push(a);
                    ans.push_back("A A\n");
                    i1++;
                }
                else{
                    B.pop();
                    A.push(b);
                    ans.push_back("B A\n");
                    i2++;
                }
            }
            while(i1<n1){
                int a=A.front();
                A.pop();
                A.push(a);
                ans.push_back("A A\n");
                i1++;
            }
            while(i2<n2){
                int b=B.front();
                B.pop();
                A.push(b);
                ans.push_back("B A\n");
                i2++;
            }
        }
    }

    int sz=ans.size();
    cout << sz << '\n';
    for(int i=0;i<sz;i++){
        cout << ans[i];
    }

    while(!A.empty()){
        int a=A.front();
        cout << a << ' ';
        A.pop();
    }
    cout << '\n';
} 