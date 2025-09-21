#include <stdio.h>

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    for (int i = 0; i < size; i++) {
        printf("%i ", arr[i]);
    }
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
    reverse(a, n);
}