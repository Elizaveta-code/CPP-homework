#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float* get_geometric_progression(float a, float r, int n){
    float* p = (float*)malloc(sizeof(float)*n);
    for (int i = 0; i < n; i++){
        p[i]=a*pow(r, i);
        printf("%.2f ", p[i]);
    }
    return p;
}
int main(){
    float* progression = get_geometric_progression(1, 3, 10);
    free(progression);
}