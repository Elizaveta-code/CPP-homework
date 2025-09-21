#include <stdio.h>

void print_even(int a, int b){
    int first;
    int i;
    if (a%2 == 0)
        first = a;
    else   
        first = a+1;
    for (i = first; i <= b; i += 2){
        printf("%i ", i);
    }
}

int main()
{
    int a;
    int b;
    scanf("%i", &a);
    scanf("%i", &b);
    print_even(a, b);
}