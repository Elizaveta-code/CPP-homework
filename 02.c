#include <stdio.h>
#include <inttypes.h>

unsigned long long a(int n, int k)
{
    if (k < 0 || k > n) return 0;
    
    unsigned long long result = 1;
    for (int i = 0; i < k; i++)
    {
        result *= (n - i);
    }
    return result;
}

int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    printf("%llu\n", a(n, k));
}