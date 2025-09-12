#include <stdio.h>
int main() 
{
    int n;
    int count = 1;
    int a[1000];
    scanf("%i", &n);
    a[0]=n;
    int max = n;
    while (n != 1) 
    {
        if (n%2 == 1){
            n=3*n+1;
        }
        else {
            n=n/2;
        }

        if (n > max){
            max = n;
        }
        a[count]=n;
        count++;
    }
    for (int i = 0; i < count; i++) {
        printf("%i ", a[i]);
    }
    printf("\nLength = %i, Max = %i", count, max);
}

    