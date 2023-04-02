class dsu {
   public:
    int n;
    vector<int> p , sz ;
    dsu(int k) : n(k), p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (sz[x] < sz[y]) swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
            sz[y] = 0 ;
            return true ;
        }
        return false;
    }
};
