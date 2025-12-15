#include <bits/stdc++.h>

using namespace std;

struct SparseTable {
    int n;
    vector<vector<int>> st;
    vector<int> lg;

    // 你可以将这个 op 改成 min / max / gcd
    int op(int a, int b) {
        return min(a, b);   // 这里默认 RMQ 最小值
    }

    SparseTable(const vector<int>& a) {
        n = a.size();
        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;
        st.assign(K, vector<int>(n));
        st[0] = a;   // 第 0 层直接就是数组本身

        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = op(st[k-1][i], st[k-1][i + (1 << (k-1))]);
            }
        }
    }

    // 查询区间 [l, r]
    int query(int l, int r) {
        int k = lg[r - l + 1];
        return op(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main() {
    vector<int> a = {5, 2, 4, 7, 1, 3, 6};

    SparseTable st(a);

    cout << st.query(0, 3) << "\n"; 

    return 0;
}
