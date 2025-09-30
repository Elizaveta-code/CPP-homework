#include <stdio.h>

int main() {
    int sum = 0;
    char d;
    while ((d = getchar()) != '\n') {
        if (d >= '0' && d <= '9') {
            sum += d - '0';
        }
    }
    printf("%d", sum);
}