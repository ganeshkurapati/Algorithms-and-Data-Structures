#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double randBtw(double first, double second)
{
    double x= second-first;
    x = (rand()% (int)x)+first;
    return (x);
}

int PARTITION(int *At, int p, int r)
{
    int x = At[r];
    int i = p-1;
    int j,m = 0;
    for (j =p; j<=r-1; j++)
    {
        if(At[j] == x)
            m++;
        if(At[j] <= x)
        {
            i++;
            int tmp = At[i];
            At[i] = At[j];
            At[j] = tmp;
        }
    }
    int tmp2 = At[i+1];
    At[i+1] = At[r];
    At[r] = tmp2;
    return (i+1)-m/2;
}

int RANDOMIZED_PARTITION(int *At, int p, int r)
{
    int i = (int)randBtw(p,r);
    int tmp = At[r];
    At[r] = At[i];
    At[i] = tmp;
    return PARTITION(At,p,r);
}

void RANDOMIZED_QUICKSORT(int *At, int p, int r)
{
    if(p<r)
    {
        int q = RANDOMIZED_PARTITION(At,p,r);
        RANDOMIZED_QUICKSORT(At,p,q-1);
        RANDOMIZED_QUICKSORT(At,q+1,r);
    }
}

int main()
{
    int k ;
    int A[12]={143,9,7,999,37,88,222,335,66,0,0,0};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    RANDOMIZED_QUICKSORT( A,0,(lengthof_A-1));
    for(k=0; k < lengthof_A ;k++)
        printf("%d,",A[k]);
    return 0;
}
