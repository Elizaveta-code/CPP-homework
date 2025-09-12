#include <stdio.h>

int main() {
    int a[1000];
    int n;
    scanf("%i", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    
    int new_i = 0; 
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            a[new_i] = a[i];
            new_i++;
        }
    }
    n = new_i;
    for (int i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}