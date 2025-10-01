#include <stdio.h>
#include <string.h>

void safe_strcpy(char* destination, size_t new_size, const char* source)
{
    if (new_size == 0)
        return;
    size_t i;
    for (i = 0; (i < new_size - 1) && (source[i] != '\0'); i++)
        destination[i] = source[i];
    destination[i] = '\0';
    printf("%s", destination);
}

int main()
{
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";
    safe_strcpy(a, sizeof(a), b);
}
