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
    segtree(vector<M>& v)
    {
        n = v.size() ;
        tree.resize(4 * n) ;
        build(0 , 0 , n - 1 , v) ;
    }
 
    template<typename M>
    void build(int idx , int l , int r , vector<M>& v)
    {
        if (l == r)
        {
            tree[idx].apply(v[l]) ;    // base apply to leaves
            return ;
        }
 
        int mid = (l + r) / 2 ;
        build(2 * idx + 1 , l , mid , v) ;
        build(2 * idx + 2 , mid + 1 , r , v) ;
        tree[idx] = combine(tree[2 * idx + 1] , tree[2 * idx + 2]) ;
    }
 
    node get(int idx , int l , int r , int ll , int rr)
    {
        if (l == ll && r == rr)
        {
            return tree[idx] ;
        }
 
        int mid = (ll + rr) / 2 ;
        if (l > mid)
        {
            return get(2 * idx + 2 , l , r , mid + 1 , rr) ;
        }
        else if (r <= mid)
        {
            return get(2 * idx + 1 , l , r , ll , mid) ;
        }
        else
        {
            return combine(get(2 * idx + 1 , l , mid , ll , mid) ,
                           get(2 * idx + 2 , mid + 1 , r , mid + 1 , rr)) ;
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
 
    void update(int idx , int p , int to , int ll , int rr)
    {
        if (ll == rr)
        {
            tree[idx].apply(to) ;    // update type
            return ;
        }
 
        int mid = (ll + rr) / 2 ;
        if (p <= mid)
        {
            update(2 * idx + 1 , p , to , ll , mid) ;
        }
        else
        {
            update(2 * idx + 2 , p , to , mid + 1 , rr) ;
        }
        tree[idx] = combine(tree[2 * idx + 1] , tree[2 * idx + 2]) ;
    }
 
    void update(int p , int to)
    {
        update(0 , p , to , 0 , n - 1) ;
    }
};
