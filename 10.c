#include <stdio.h>
#define MAX 100

void assign(float A[MAX][MAX], float B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}
int main() {
    float matrix1[MAX][MAX];
    float matrix2[MAX][MAX];
    int n;
    printf("size: ");
    scanf("%i", &n);
    
    printf("matrix B (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix2[i][j]);
        }
    }
    // Копирование из B в A
    assign(matrix1, matrix2, n);
    // Вывод матрицы A
    printf("Matrix A after:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.1f ", matrix1[i][j]);
        }
        printf("\n");
    }
}