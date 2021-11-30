vector<int> spf(int n)
{
    vector<int> v(n + 1) ;
    iota(v.begin(), v.end(), 0) ;
    for (int i = 2 ; i * i <= n ; i++)
    {
        if (v[i] == i)
        {
            for (int j = i * i ; j < n + 1 ; j += i)
            {
                if (v[j] == j)
                {
                    v[j] = i ;
                }
            }
        }
    }
    v[0] = v[1] = -1 ;
    return v ;
}
