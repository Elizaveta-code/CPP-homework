#include <stdio.h>

int main() {
    int m;
    int n;
    int sum = 0;
    scanf("%i", &n);
    scanf("%i", &m);
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if ((i+j)%2 == 1)
                sum += -i*j;
            else
                sum +=i*j;
        }
    }
    printf("%i", sum);
}