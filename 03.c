#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game {
    char title[50];
    double average_rating;
};

int main() {
    int n;
    scanf("%i", &n);
    getchar();

    struct game games[100];
    
    for (int i = 0; i < n; i++) {
        char temp;
        scanf("%[^:]", games[i].title);
        scanf("%c", &temp);
        
        int k;
        scanf("%i", &k);
        int sum = 0;
        for (int j = 0; j < k; j++) {
            int rating;
            scanf("%i", &rating);
            sum += rating;
        }
        
        games[i].average_rating = (double)sum / k;
        while (getchar() != '\n');
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (games[j].average_rating < games[j + 1].average_rating) {
                struct game temp = games[j];
                games[j] = games[j + 1];
                games[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].title, games[i].average_rating);
    }
}