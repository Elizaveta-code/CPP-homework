/* Долгая реализация через рекурсию
#include <stdio.h>

int trib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return trib(n - 3) + trib(n - 2) + trib(n - 1);
    }

int main() {
    int n;
    scanf("%i", &n);
    printf("%i", trib(n));
}*/
// быстрая реализация
#include <stdio.h>

int trib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;
    int a = 0, b = 0, c = 1;
    int result;
    for (int i = 3; i <= n; i++) {
        result = a + b + c;
        a = b;
        b = c;
        c = result;
    }
    return result;
}

int main() {
    int n;
    scanf("%i", &n);
    printf("%i", trib(n));
}