#include <stdio.h>
#define MAX 100

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void assign(float A[MAX][MAX], float B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void power(float A[MAX][MAX], float C[MAX][MAX], int n, int k) {
    float B[MAX][MAX], temp[MAX][MAX];
    
    if (k == 0) {
        // A^0 = единичная матрица
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
        return;
    }
    if (k == 1) {
        // A^1 = A
        assign(C, A, n);
        return;
    }
    
    assign(C, A, n);  // C = A
    assign(B, A, n);  // B = A
    
    for (int i = 1; i < k; i++) {
        multiply(A, B, temp, n); // temp = A × B
        assign(C, temp, n);      // C = temp
        assign(B, C, n);         // B = C для следующей итерации
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float A[MAX][MAX], C[MAX][MAX];
    int n, k;
    
    printf("size: ");
    scanf("%i", &n);
    
    printf("matrix A (%ix%i):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }
    printf("power: ");
    scanf("%i", &k);
    power(A, C, n, k);
}