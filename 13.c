#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_integer(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }
    int i = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }
    if (str[i] == '\0') {
        return 0;
    }
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: %s <number> <operator> <number>\n", argv[0]);
        return 1;
    }
    
    if (!is_integer(argv[1]) || !is_integer(argv[3])) {
        printf("Error: Operands should be integers!");
        return 1;
    }
    if (strlen(argv[2]) != 1) {
        printf("Error: Operator must be a single character!\n");
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    char operator = argv[2][0];
    
    switch (operator) {
        case '+':
            printf("%d\n", num1 + num2);
            break;
        case '-':
            printf("%d\n", num1 - num2);
            break;
        case '*':
            printf("%d\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            printf("%d\n", num1 / num2);
            break;
        case '%':
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            printf("%d\n", num1 % num2);
            break;
        default:
            printf("Error: Invalid operator '%c'!\n", operator);
            return 1;
    }
}
