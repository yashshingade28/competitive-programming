template <typename T>
class fenwick {
public:
    int n;
    vector<T> fen;
    fenwick(int _n) : n(_n) {
        fen.resize(n);
    }
    void modify(int x, T v) {
        while (x < n) {
            fen[x] += v;
            x |= (x + 1);
        }
    }
    T get(int x) {
        T v{} ;
        while (x >= 0) {
            v += fen[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};
