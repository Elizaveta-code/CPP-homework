#include <stdio.h>
#include <string.h>

int main() {
    char word1[100], word2[100];
    scanf("%s", word1);
    scanf("%s", word2);
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    if (len1 > len2) {
        for (int i = 0; i < len2; i++) {
            printf("%c%c", word1[i], word2[i]);
        }
        for (int i = len2; i < len1; i++) {
            printf("%c", word1[i]);
        }
    }
    else {
        for (int i = 0; i < len1; i++) {
            printf("%c%c", word1[i], word2[i]);
        }
        for (int i = len1; i < len2; i++) {
            printf("%c", word2[i]);
        }
    }
}