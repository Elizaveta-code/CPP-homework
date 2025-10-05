#include <stdio.h>
#include <math.h>

#define EPS 1e-10
int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    if (fabs(a) < EPS) {
        if (fabs(b) < EPS) {
            return 0;
        }
        *px1 = -c / b;
        return 1;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant < -EPS) {
        return 0;
    }
    else if (fabs(discriminant) < EPS) {
        *px1 = -b / (2 * a);
        return 1;
    }
    else {
        double sqrt_d = sqrt(discriminant);
        *px1 = (-b - sqrt_d) / (2 * a);
        *px2 = (-b + sqrt_d) / (2 * a);
        return 2;
    }
}
int main() {
    double x1, x2;
    int result;
    result = solve_quadratic(0, 2, -4, &x1, &x2);
    printf("%i\n", result);   // 2x - 4 = 0, один корень: 2
    if (result >= 1) printf("x1 = %.2f\n", x1);
    if (result == 2) printf("x2 = %.2f\n", x2);
}