#include <stdio.h>
#include <stdlib.h>
void mergesort(int *At,int p,int q);
void merge(int *At,int p,int q,int r);
int main()
{
    int k ;
    int A[10]={143,9,7,999,37,88,222,335,66,0};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    mergesort( A,0,(lengthof_A-1));
    for(k=0; k < lengthof_A ;k++)
        printf("%d,",A[k]);
    return 0;
}
void merge(int *At,int p,int q,int r)
{
    int n1, n2, i,j,k;
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
    i = 0; j= 0;
    for (k=p; k<=r; k++)
    {
        if (i >= n1)
            At[k] = R[j++];
        else if (j >= n2)
            At[k] = L[i++];
        else if(L[i] <= R[j])
            At[k] = L[i++];
        else
            At[k] = R[j++];
    }
}
void mergesort(int *At,int p,int r)
{
    if(p < r){
       int q = (p + r) / 2;
       mergesort(At, p, q);
       mergesort(At, q + 1, r);
       merge(At, p, q, r);
    }
}
