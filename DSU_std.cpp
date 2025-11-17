#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // 路径压缩
        return parent[x];
    }

    bool unite(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;  // 已连通，不能合并
        if (rank[fx] < rank[fy]) swap(fx, fy);
        parent[fy] = fx;
        if (rank[fx] == rank[fy]) rank[fx]++;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
