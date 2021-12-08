// code to solve the equation x*x = n for x given n .
class eqnsolver {
private:
    long long eqn(long long x)
    {
        return x * x;
    }

public:
    // this function finds the root of eqn(x) = n from l+1 to r-1 . 
    pair<long long , long long> solve(long long n)
    {
        long long x , l = -1 , r = 3e9 + 1;
        while (r - l > 1)
        {
            x = (l + r) / 2;
            if (eqn(x) < n)
            {
                l = x;
            }
            else if (eqn(x) > n)
            {
                r = x;
            }
            else
            {
                return {x , x};
            }
        }
        return {l , r};
    }
};
// if the root of the equation is integer then l==r==root
// else the root lies within (l,r) where r == l+1 
