class LCA {
   public:
    int n;
    vector<int> first;
    vector<array<int, 2>> euler;
    vector<vector<array<int, 2>>> mat;
    function<array<int, 2>(array<int, 2>, array<int, 2>)> func = [](array<int, 2> a, array<int, 2> b) {
        if (a[1] < b[1]) return a;
        else return b;
    };

    LCA(const vector<vector<int>>& adj) : n(adj.size()) {
        first.assign(n, INT_MAX);
        build_euler(0, -1, 0, adj);
        build_sparse_table();
    }

    void build_euler(int node, int par, int lvl, const vector<vector<int>>& adj) {
        first[node] = min(first[node], int(euler.size()));
        euler.emplace_back(array<int, 2>({node, lvl}));
        for (int i : adj[node]) {
            if (i != par) {
                build_euler(i, node, lvl + 1, adj);
                euler.emplace_back(array<int, 2>({node, lvl}));
            }
        }
    }

    void build_sparse_table() {
        int sz = 2 * n - 1;
        int max_log = 32 - __builtin_clz(sz);
        mat.resize(max_log);
        mat[0] = euler;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(sz - (1 << j) + 1);
            for (int i = 0; i <= sz - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int query(int u, int v) {
        if (first[u] > first[v]) swap(u, v);
        int lg = 32 - __builtin_clz(first[v] - first[u] + 1) - 1;
        return func(mat[lg][first[u]], mat[lg][first[v] - (1 << lg) + 1])[0];
    }
};
