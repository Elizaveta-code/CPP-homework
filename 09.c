#include <stdio.h>
int adder(int x)
{
    static int total = 0;
    total += x;
    return total;
}
int main()
{
    printf("%i\n", adder(10)); // Должен напечатать 10
    printf("%i\n", adder(15)); // Должен напечатать 25
    printf("%i\n", adder(70)); // Должен напечатать 95
}