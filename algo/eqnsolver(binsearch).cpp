class eqnsolver {
   public:
    int64_t eqn(int64_t x) { return x * x; }
    
    // finds answer for eqn(x) = n between l+1 and r-1
    pair<int64_t, int64_t> solve(int64_t n) {
        int64_t x, l = -1, r = 3e9 + 1;
        while (r - l > 1) {
            x = (l + r) / 2;
            if (eqn(x) < n) {
                l = x;
            } else if (eqn(x) > n) {
                r = x;
            } else {
                return {x, x};
            }
        }
        return {l, r};
    }
};

// Usage :
// if the root of the equation is integer then l==r==root
// else the root lies within (l,r) where r == l+1 
