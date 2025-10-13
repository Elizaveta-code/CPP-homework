#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** strings = (char**)malloc(4 * sizeof(char*));
    strings[0] = (char*)malloc(4 * sizeof(char));
    strcpy(strings[0], "Cat");
    
    strings[1] = (char*)malloc(9 * sizeof(char));
    strcpy(strings[1], "Elephant");
    
    strings[2] = (char*)malloc(6 * sizeof(char));
    strcpy(strings[2], "Mouse");

    strings[3] = NULL;
    return strings;
}

void print_strings(const char** string_array) {
    for (int i = 0; string_array[i] != NULL; i++) {
        printf("%s\n", string_array[i]);
    }
}

size_t* get_sizes(const char** string_array) {
    int count = 0;
    while (string_array[count] != NULL) {
        count++;
    }
    size_t* sizes = (size_t*)malloc(count * sizeof(size_t));
    for (int i = 0; i < count; i++) {
        sizes[i] = strlen(string_array[i]);
    }
    return sizes;
}

char** load_lines(const char* filename) {
    FILE* file = fopen(filename, "r");
    
    int line_count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') 
            line_count++;
    }
    line_count++;
    
    int* lengths = (int*)malloc(line_count * sizeof(int));

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < line_count; i++) {
        lengths[i] = 0;
        while ((ch = fgetc(file)) != EOF && ch != '\n') {
            lengths[i]++;
        }
        lengths[i]++;
    }
    
    fseek(file, 0, SEEK_SET);
    
    char** lines = (char**)malloc((line_count + 1) * sizeof(char*));
    
    for (int i = 0; i < line_count; i++) {
        lines[i] = (char*)malloc(lengths[i] * sizeof(char));
        int j = 0;
        while ((ch = fgetc(file)) != EOF && ch != '\n') {
            lines[i][j++] = ch;
        }
        lines[i][j] = '\0';
    }
    lines[line_count] = NULL;
    
    free(lengths);
    fclose(file);
    return lines;
}

void destroy_strings(char*** p_string_array) {
    char** strings = *p_string_array;
    for (int i = 0; strings[i] != NULL; i++) {
        free(strings[i]);
    }
    free(strings);
    *p_string_array = NULL;
}

int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void sort_strings(char** words) {
    int count = 0;
    while (words[count] != NULL) {
        count++;
    }
    qsort(words, count, sizeof(char*), compare_strings);
}

int main(int argc, char* argv[]) {
    char** lines = load_lines(argv[1]);
    
    sort_strings(lines);
    
    FILE* output = fopen(argv[2], "w");
    
    for (int i = 0; lines[i] != NULL; i++) {
        fprintf(output, "%s\n", lines[i]);
    }
    
    fclose(output);
    destroy_strings(&lines);
}