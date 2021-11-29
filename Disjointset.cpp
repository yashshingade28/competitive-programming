class dsu {
public:
    int n;
    vector<int> p;
    vector<int> sz;

    dsu(int k) : n(k) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }

    int root(int x) {
        return (x == p[x] ? x : (p[x] = root(p[x])));
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (sz[x] < sz[y])
                swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
            sz[y] = 0 ;
            return true ;
        }
        return false;
    }
};
