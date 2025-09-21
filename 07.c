#include <stdio.h>

int count_even(int arr[], int size) {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            cnt++;
    }
    return cnt;
}

int main() {
    int a[1000];
    int n;
    printf("array: ");
    int i = 0;
    while (scanf("%i", &a[i]) == 1 && getchar() != '\n') {
        i++;
    }    
    printf("size: ");
    scanf("%i", &n);
    printf("%i", count_even(a, n));
}