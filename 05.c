#include <stdio.h>
#include <math.h>

#define EPS 1e-5

int main()
{
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx*dx + dy*dy);
    double sum_r = r1 + r2;
    double dr = fabs(r1 - r2);
    if (fabs(d - sum_r) < EPS || fabs(d - dr) < EPS)
    {
        printf("Touch");
    }
    else if (d > sum_r + EPS || d + EPS < dr)
    {
        printf("Do not intersect");
    }
    else
    {
        printf("Intersect");
    }
}