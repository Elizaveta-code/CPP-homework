// тип int в языке C имеет максимальное значение 2 147 483 647. Факториал числа 13 (6 227 020 800) уже превышает это значение.
// Тип long long int позволяет представлять числа до 9 223 372 036 854 775 807, что достаточно для вычисления факториалов до 20 включительно.
#include <stdio.h>

long long fact(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main()
{
    int k;
    scanf("%i", &k);
    printf("%lli\n", fact(k));
}