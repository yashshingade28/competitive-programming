// code to solve the equation x*(x+1) = n for x given n .
ll n , x;
cin >> n;

// here l and r are the strict lower and upper bounds of the root x .
ll l = 1, r = 1e9;

while (r - l > 1)
{
    x = (l + r) / 2;
    cerr << l << " " << r << endl;
    if (x * (x + 1) == n)
    {
        l = x;
        r = x;
        break;
    }
    else if (x * (x + 1) < n)
    {
        l = x;
    }
    else if (x * (x + 1) > n)
    {
        r = x;
    }
}
// if the root of the equation is integer then l==r==root
// else the root lies within (l,r) where r == l+1 
