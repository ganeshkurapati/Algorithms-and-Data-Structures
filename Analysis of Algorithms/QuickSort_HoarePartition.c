#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int HOARE_PARTITION(int *At, int p, int r)
{
    int x = At[p];
    int i = p-1;
    int j = r+1;
    while(1)
    {
        do {j--;}
        while(!(At[j] <= x));
        do {i++;}
        while(!(At[i] >= x));
        if(i<j)
        {
            int tmp = At[i];
            At[i] = At[j];
            At[j] = tmp;
        }
        else
            return j;
    }
}

int QUICKSORT(int *At, int p, int r)
{
    if(p<r)
    {
        int q = HOARE_PARTITION(At,p,r);
        QUICKSORT(At,p,q-1);
        QUICKSORT(At,q+1,r);
    }
}

int main()
{
    int k ;
    int A[11]={143,9,7,999,37,88,222,335,66,0,0};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    QUICKSORT( A,0,(lengthof_A-1));
    for(k=0; k < lengthof_A ;k++)
        printf("%d,",A[k]);
    return 0;
}

