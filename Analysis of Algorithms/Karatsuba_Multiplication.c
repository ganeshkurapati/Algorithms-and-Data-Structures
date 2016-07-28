#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int karatsuba_multiply(int num1, int num2);

int main()
{
    printf("%d",karatsuba_multiply(1234,5678));
    return 0;
}
int karatsuba_multiply(int num1, int num2)
{
    if ((num1 < 10) || (num2 < 10))
        return num1*num2;
    int m = (int) MAX((log10(num1) + 1), (log10(num1) + 1));
    int m2 = m/2;
    int a = (int) (num1/pow(10,m2));
    int b = (int) (num1 - a*pow(10,m2));

    int c= (int) (num2/pow(10,m2));
    int d = (int) (num2 - c*pow(10,m2));

    int ac = karatsuba_multiply(a, c);
    int bd = karatsuba_multiply(b, d);
    int ad_plus_bc = (karatsuba_multiply((a+b),(c+d))) - ac - bd;
    return (pow(10,2*m2)*ac + pow(10,m2)*ad_plus_bc + bd);

}
