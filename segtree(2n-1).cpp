class segtree
{
public:
    int n ;
    struct node
    {
        // base apply for leaves
        void apply()
        {

        }
    };
    vector<node> tree ;
 
    // combining child nodes to get parent node
    node combine(node a , node b)
    {
        node res ;
        return res ;
    }
 
    template<typename M>
    segtree(const vector<M>& v)
    {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0 , 0 , n - 1 , v);
    }
 
    template<typename M>
    void build(int idx , int l , int r , const vector<M>& v)
    {
        if (l == r)
        {
            tree[idx].apply(v[l]) ;
            return ;
        }
        
        int mid = (l + r) / 2 ;
        int lidx = idx + 1 ;
        int ridx = idx + 2 * (mid - l + 1) ;
        build(lidx , l , mid , v) ;
        build(ridx , mid + 1 , r , v) ;
        tree[idx] = combine(tree[lidx] , tree[ridx]) ;    // query type
    }
 
    node get(int idx , int l , int r , int ll , int rr)
    {
        if (l == ll && r == rr)
        {
            return tree[idx] ;
        }
 
        int mid = (ll + rr) / 2 ;
        int lidx = idx + 1 ;
        int ridx = idx + 2 * (mid - ll + 1) ;
        if (r <= mid)
        {
            return get(lidx , l , r , ll , mid) ;
        }
        else if (l >= mid + 1)
        {
            return get(ridx , l , r , mid + 1 , rr) ;
        }
        else
        {
            return combine(get(idx + 1 , l , mid , ll , mid) ,
                           get(ridx , mid + 1 , r , mid + 1 , rr)) ;    // query type
        }
    }
 
    node get(int l , int r)
    {
        return get(0 , l , r , 0 , n - 1) ;
    }
 
    node get(int p)
    {
        return get(0 , p , p , 0 , n - 1) ;
    }
 
    void update(int idx , const int& p , const int& to , int ll , int rr)
    {
        if (ll == rr)
        {
            tree[idx].apply(to) ;    // update type
            return ;
        }
 
        int mid = (ll + rr) / 2 ;
        int lidx = idx + 1 ;
        int ridx = idx + 2 * (mid - ll + 1) ;
        if (p <= mid)
        {
            update(lidx , p , to , ll , mid) ;
        }
        else
        {
            update(ridx , p , to , mid + 1 , rr) ;
        }
        tree[idx] = combine(tree[lidx] , tree[ridx]) ;    // query type
    }
 
    void update(const int& p , const int& to)
    {
        update(0 , p , to , 0 , n - 1) ;
    }
};
