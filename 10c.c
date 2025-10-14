#include <stdio.h>
#define SIZE 1'000'000'000

int main()
{
    getchar();
    char data[SIZE];
    
    getchar();
    printf("1. Setting first char to 'A'\n");
    data[0] = 'A';

    getchar();
    printf("Setting last char to 'B'\n");
    data[SIZE - 1] = 'B';

    getchar();
    printf("Printing first char = %c\n", data[0]);

    getchar();
    printf("Printing last char = %c\n", data[SIZE - 1]);

    getchar();
}