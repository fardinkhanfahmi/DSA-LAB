#include <stdio.h>

#define ll long long

ll power(ll m, int n, ll y)
{
    ll res = 1;

    for (int i = 0; i < n; i++)
    {
        if (res > y / m)
            return y + 1;

        res *= m;
    }

    return res;
}

ll nth_root(ll y, int n)
{
    ll l = 1;
    ll h = y;

    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
        ll val = power(mid, n, y);

        if (val == y)
            return mid;
        else if (val < y)
            l = mid + 1;
        else
            h = mid - 1;
    }

    return -1;
}

int main()
{
    ll y;
    int n;

    printf("Enter number: ");
    scanf("%lld", &y);

    printf("Enter n: ");
    scanf("%d", &n);

    ll ans = nth_root(y, n);

    if (ans == -1)
        printf("No perfect root\n");
    else
        printf("%d-th root of %lld = %lld\n", n, y, ans);

    return 0;
}