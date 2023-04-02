struct query {
    int l, r, id;
    query(int l, int r, int id) : l(l), r(r), id(id) {}
};

template <typename T, typename Q>
class Mo {
   public:
    vector<T> a;
    const int n;
    int l, r;
    Q ans;

    Mo(vector<T> a) : a(a), n(a.size()), l(0), r(0), ans(0) {}

    void insert(const int x) {}

    void erase(const int x) {}

    vector<Q> solve(const int block_size, vector<query>& qs) {
        vector<Q> ret(qs.size());
        sort(begin(qs), end(qs), [&](query p, query q) {
            int A = (p.l) / block_size, B = (q.l) / block_size;
            if (A != B) return A < B;
            if (A % 2 == 0) return p.r < q.r;
            return p.r > q.r;
        });
        for (const query& e : qs) {
            while (e.l < l) insert(--l);
            while (r < e.r) insert(r++);
            while (l < e.l) erase(l++);
            while (e.r < r) erase(--r);
            ret[e.id] = ans;
        }
        return ret;
    }
};
