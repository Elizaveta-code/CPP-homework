#include <stdio.h>

int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    int col_sum[m];

    for (int j = 0; j < m; j++) {
        col_sum[j] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%i", &num);
            col_sum[j] += num;
        }
    }
    
    for (int j = 0; j < m; j++) {
        printf("%i ", col_sum[j]);
    }
}