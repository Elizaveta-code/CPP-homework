#include <stdio.h>
void cube(float* px){
    printf("%f", (*px)*(*px)*(*px));
}
int main(){
    float a;
    scanf("%f", &a);
    cube(&a);
}
