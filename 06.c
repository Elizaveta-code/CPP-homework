#include <stdio.h>
#include <string.h>
void is_palindrom(char a[1001]) {
    int length = strlen(a);
    for (int i = 0; i < length / 2; i++)
    {
        if (a[i] != a[length - 1 - i])
        {
            printf("No");
            return;
        }
    }
    printf("Yes");
}
int main() {
    char a[1001];
    scanf("%1000s", a);
    is_palindrom(a);
}

