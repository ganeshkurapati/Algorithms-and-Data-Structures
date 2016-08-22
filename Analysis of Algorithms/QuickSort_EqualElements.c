#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int q;
    int t;
} pivot;

double randBtw(double first, double second)
{
    double x= second-first;
    x = (rand()% (int)x)+first;
    return (x);
}

pivot PARTITION(int *At, int p, int r)
{
    int x = At[r];
    int i = p-1;
    int j=0;
    int m = i;
    for (j =p; j<=r-1; j++)
    {
        if(At[j] < x)
        {
            m++;
            int tmp1 = At[m];
            At[m] = At[j];
            At[j] = tmp1;
            i++;
            int tmp2 = At[m];
            At[m] = At[i];
            At[i] = tmp2;
        }
        else if(At[j] == x)
        {
            m++;
            int tmp3 = At[m];
            At[m] = At[j];
            At[j] = tmp3;
        }
    }

    int tmp4 = At[m+1];
    At[m+1] = At[r];
    At[r] = tmp4;
    pivot result = {i+1, m+1};
    return result;
}

pivot RANDOMIZED_PARTITION(int *At, int p, int r)
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
        pivot pt = RANDOMIZED_PARTITION(At,p,r);
        RANDOMIZED_QUICKSORT(At,p,pt.q-1);
        RANDOMIZED_QUICKSORT(At,pt.t+1,r);
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
