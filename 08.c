#include <stdio.h>
int main()
{
    int a;
    scanf("%i", &a);
    printf("a = %i\n", a);

    char str[100];
    scanf(" %[^\n]", str);  // пробел перед % поглощает пробельные символы
    printf("str = %s\n", str);
}