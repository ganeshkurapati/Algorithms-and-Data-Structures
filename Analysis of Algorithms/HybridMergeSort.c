#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INSERTION_SORT_THERSHOLD 20
void hybridmergesort(int *At,int p,int q);
void merge(int *At,int p,int q,int r);
void insertionsort(int *At, int p, int q);
int main()
{
    int k ;
    int A[11]={143,9,7,999,37,88,222,335,66,0,0};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    hybridmergesort( A,0,(lengthof_A-1));
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
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0; j= 0;
    for (k=p; k<=r; k++)
    {
        if(L[i] <= R[j])
            At[k] = L[i++];
        else
            At[k] = R[j++];
    }
}
void hybridmergesort(int *At,int p,int r)
{
    if(p - r < INSERTION_SORT_THERSHOLD)
        insertionsort(At, p, r);
    if(p < r){
       int q = (p + r) / 2;
       hybridmergesort(At, p, q);
       hybridmergesort(At, q + 1, r);
       merge(At, p, q, r);
    }
}
void insertionsort(int *At, int p, int q)
{
    int i,j,key;
    for(j=p+1;j<=q;j++)
    {
        key = At[j];
        i=j-1;
        while ((i >= p ) && (At[i] > key))
        {
            At[i+1] = At[i];
            i=i-1;
        }
        At[i+1] = key;
    }
}
