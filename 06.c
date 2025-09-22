#include <stdio.h>
#include <math.h>

#define STEP 1e-2
#define EPS 1e-10

double gamma(double x)
{
    double integral = 0.0;
    double t = STEP;
    while (1)
    {
        double f_current = pow(t, x-1) * exp(-t);
        double f_next = pow(t + STEP, x-1) * exp(-(t + STEP));
        double s = STEP * (f_current + f_next) / 2.0;
        if (s < EPS && t > 100)
            break;
        integral += s;
        t += STEP;
    }
    return integral;
}

int main()
{
    double x;
    scanf("%lf", &x);
    printf("%.6g", gamma(x));
}