#include "stdio.h"
#include "math.h"

int main()
{
    double n;
    printf("Input n: ");
    scanf_s("%lf", &n);

    double res = log10(n);

    printf("log10(%lf) = %.3lf\n", n, res);
}