#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double randBtw(double first, double second)
{
    double x= second-first;
    x = (rand()% (int)x)+first;
    return (x);
}

typedef struct
{
    int left;
    int right;
} interval;

interval FIND_INTERSECTION(interval *At, int p, int r)
{
    int i = (int)randBtw(p,r);
    interval tmp = At[r];
    At[r] = At[i];
    At[i] = tmp;
    int k;
    interval pivot_intersection = At[r];
    for(k=p; k<=r-1;k++)
    {
        if((At[k].left<=pivot_intersection.right)&&(At[k].right>=pivot_intersection.left))
        {
            if(At[k].left > pivot_intersection.left)
                pivot_intersection.left = At[k].left;
            if(At[k].right < pivot_intersection.right)
                pivot_intersection.right = At[k].right;
        }
    }
    return pivot_intersection;
}

int PARTITION_RIGHT(interval *At, int a, int p, int r)
{
    int i = p-1;
    int j =0;
    for(j=p;j<=r-1;j++)
    {
        if(At[j].left<=a)
        {
            i++;
            interval tmp = At[j];
            At[j] = At[i];
            At[i] = tmp;
        }
    }
    interval tmp1 = At[i+1];
    At[i+1] = At[r];
    At[r] = tmp1;
    return (i+1);
}

int PARTITION_LEFT_MIDDLE(interval *At, int b, int p, int rp)
{
    int i = p-1;
    int j =0;
    for(j=p;j<=rp-1;j++)
    {
        if(At[j].right<b)
        {
            i++;
            interval tmp = At[j];
            At[j] = At[i];
            At[i] = tmp;
        }
    }
    interval tmp1 = At[i+1];
    At[i+1] = At[rp];
    At[rp] = tmp1;
    return (i+1);
}

void FUZZYSORT(interval *At, int p, int r)
{
    if(p<r)
    {
        interval pivot_intersection = FIND_INTERSECTION(At, p, r);
        int right_pivot = PARTITION_RIGHT(At, pivot_intersection.left, p, r);
        int left_pivot = PARTITION_LEFT_MIDDLE(At,pivot_intersection.right,p,right_pivot);
        FUZZYSORT(At,p,left_pivot-1);
        FUZZYSORT(At,right_pivot+1,r);
    }
}

int main()
{
    int k ;
    interval A[6]={{1,2},{1,8},{85,88},{222,335},{60,66},{0,0}};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("[%d,%d]",A[k].left,A[k].right);
    printf("\n");
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    FUZZYSORT( A,0,(lengthof_A-1));
    for(k=0; k < lengthof_A ;k++)
        printf("[%d,%d]",A[k].left,A[k].right);
    return 0;
}
