#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int mergesort(int *At,int p,int q);
int merge(int *At,int p,int q,int r);
int main()
{
    int k ,inversions;
    int A[11]={143,9,7,999,37,88,222,335,66,0,0};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    inversions = mergesort( A,0,(lengthof_A-1));
    for(k=0; k < lengthof_A ;k++)
        printf("%d,",A[k]);
    printf(" \n %d",inversions);
    return 0;
}
int merge(int *At,int p,int q,int r)
{
    int n1, n2, i,j,k;
    int split_inversions = 0;
    n1 = q - p +1;
    n2 = r - q ;
    int L[n1+1],R[n2+1];
    for (i=0; i<n1; i++)
    {
        L[i] = At[p+i];
    }
    for (j=0; j<n2; j++)
    {
        R[j] = At[q + 1 + j];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0; j= 0;
    for (k=p; k<=r; k++)
    {
        if(L[i] <= R[j])
            At[k] = L[i++];
        else
        {
            split_inversions = split_inversions + (n1 - i);
            At[k] = R[j++];
        }
    }
    return split_inversions;
}
int mergesort(int *At,int p,int r)
{
    if(p < r){
       int q = (p + r) / 2;
       int x,y,z;
       x = mergesort(At, p, q);
       y = mergesort(At, q + 1, r);
       z = merge(At, p, q, r);
       return (x+y+z);
    }
    else
        return 0;
}
