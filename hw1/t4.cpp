#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        stack<pair<int,int>> st;
        int ans=0;
        for(int i=0;i<n;i++){
            int h;
            cin >> h;
            if(st.size()==0){
                st.push({h,1});
                continue;
            }
            auto &[height,cnt]=st.top();
            if(h<height){
                st.push({h,1});
                ans++;   
            }
            else if(h==height){
                ans+=cnt;
                cnt++;
                if(st.size()!=1){
                    ans++;
                }
            }
            else{
                while(true){
                    ans+=st.top().second;
                    st.pop();
                    if(st.size()==0){
                        st.push({h,1});
                        break;
                    }
                    auto &[hei,c]=st.top();
                    if(hei==h){
                        ans+=c;
                        c++;
                        if(st.size()!=1){
                            ans++;
                        }
                        break;
                    }
                    else if(hei>h){
                        ans++;
                        st.push({h,1});
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}