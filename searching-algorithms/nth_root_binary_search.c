#include <stdio.h>

double power(double mid, int n)
{
    double res = 1.0;

    for (int i = 0; i < n; i++)
    {
        res *= mid;
    }

    return res;
}

double nth_root(double y, int n)
{
    double l = 0.0;
    double h = y > 1.0 ? y : 1.0;
    double eps = 0.000001;

    while (h - l > eps)
    {
        double mid = l + (h - l) / 2.0;

        if (power(mid, n) < y)
            l = mid;
        else
            h = mid;
    }

    return (l + h) / 2.0;
}

int main()
{
    double y;
    int n;

    printf("Enter number: ");
    scanf("%lf", &y);

    printf("Enter n: ");
    scanf("%d", &n);

    printf("%d-th root of %.2lf = %.6lf\n", n, y, nth_root(y, n));

    return 0;
}