#include <stdio.h>

int sum_of_digits(int a){
    int sum = 0;
    while (a != 0){
        sum += a%10;
        a = a / 10;
    }
    return sum;
}

int sum_of_digits_rec(int a) {
    if (a == 0) {
        return 0;
    }
    return a % 10 + sum_of_digits_rec(a / 10);
}

int main()
{
    int a;
    scanf("%i", &a);
    printf("%i\n", sum_of_digits(a));
    printf("%i\n", sum_of_digits(a));
}