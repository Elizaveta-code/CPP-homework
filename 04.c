#include <stdio.h>

double pi(int n)
{
    double sum = 0.0;
    int sign = 1;
    for (int i = 1; i <= n; i++)
    {
        double term = sign / (2.0 * i - 1.0);
        sum += term;
        sign = -sign;
    }
    return 4 * sum;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%.10f", pi(n));
}