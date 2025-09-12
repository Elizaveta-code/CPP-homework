#include <stdio.h>
#include <limits.h>
int main() 
{
    int n;
    int i;
    int count;
    scanf("%i", &n);
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) 
    {
        int a;
        scanf("%i", &a);
        if (a > max){
            max = a;
            count = 1;
        }
        else if (a==max){
            count++;
        }
    }
    printf("%i %i", max, count);
}