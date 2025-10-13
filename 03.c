#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char* concat(const char* a, const char* b){
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    size_t total_len = len_a + len_b + 1;
    char* result = (char*)malloc(total_len);
    strcpy(result, a);
    strcpy(result + len_a, b);
    return result;
}
int main(){
    char* merge = concat("Hello ", "World!");
    printf("%s", merge);
    free(merge);
}