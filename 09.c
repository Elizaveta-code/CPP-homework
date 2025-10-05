#include <stdio.h>
#include <string.h>
#include <ctype.h>
void used_chars(const char* str, char* used) {
    int words[26] = {0};
    while (*str != '\0') {
        if (isalpha(*str)) {
            char low_char = tolower(*str);
            words[low_char - 'a'] = 1;
        }
        str++;
    }
    int index = 0;
    for (int i = 0; i < 26; i++) {
        if (words[i]) {
            used[index++] = 'a' + i;
        }
    }
    used[index] = '\0';
}
int main() 
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);
    
    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u);
    
    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);   
}