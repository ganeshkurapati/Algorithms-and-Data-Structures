#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
long long int mergesort(int *At,int p,int q);
long long int merge(int *At,int p,int q,int r);
int main()
{
    int k ;
    long long int inversions;
    int A[100000] = {0};
    FILE *fptr;
    fptr = fopen("IntegerArray.txt" , "r");
    if (fptr == NULL)
    {
    printf("\n Can't open the file \n");
    exit(1);
    }
    int i = 0;
    while (!feof(fptr))
    {
        fscanf(fptr, "%d", &A[i++]);
    }
    fclose(fptr);
    /*for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");*/
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    inversions = mergesort( A,0,(lengthof_A-1));
    for(k=0; k < lengthof_A ;k++)
        printf("%d,",A[k]);
    printf(" \n %lld",inversions);
    return 0;
}
long long int merge(int *At,int p,int q,int r)
{
    int n1, n2, i,j,k;
    long long int split_inversions = 0;
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
long long int mergesort(int *At,int p,int r)
{
    if(p < r){
       int q = (p + r) / 2;
       long long int x,y,z;
       x = mergesort(At, p, q);
       y = mergesort(At, q + 1, r);
       z = merge(At, p, q, r);
       return (x+y+z);
    }
    else
        return 0;
}
