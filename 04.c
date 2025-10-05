#include <stdio.h>
void mult2_a(int* p, size_t n) {
    for (size_t i = 0; i < n; i++) {
        *(p + i) *= 2;
    }
}
void mult2_b(int* p, size_t n) {
    for (size_t i = 0; i < n; i++) {
        p[i] *= 2;
    }
}
void print(int* p, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%i ", p[i]);
    }
    printf("\n");
}
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    size_t n = 5;   
    mult2_a(arr1, n);
    print(arr1, n);
    mult2_b(arr2, n);
    print(arr2, n);
}