#include <stdio.h>
int sums(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() 
{
    int n;
    scanf("%i", &n);
    int a[n]; 

    for (int i = 0; i < n; i++) {
        scanf("%i", &a[i]);
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n - 1 - j; i += 1) {
            if (sums(a[i]) > sums(a[i + 1])) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%i ", a[i]);
    }
}