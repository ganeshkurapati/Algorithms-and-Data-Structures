#include <stdio.h>
#include <stdlib.h>
void insertionsort(int *At,int size);
int iterative_binarysearch(int *At,int v,int low,int high);
int recursive_binarysearch(int *At,int v,int low,int high);
int main()
{
    int k;
    int A[11]={143,9,7,999,37,88,222,335,66,0,10};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    insertionsort(A,sizeof(A) / sizeof(A[0]));
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    printf("iterative binarysearch : %d",iterative_binarysearch(A, 222,0,10));
    printf("\n");
    printf("recursive binarysearch: %d",recursive_binarysearch(A, 222,0,10));
    return 0;
}
void insertionsort(int *At, int size)
{
    int i,j,key;
    for(j=1;j<size;j++)
    {
        key = At[j];
        i=j-1;
        while ((i >= 0 ) && (At[i] > key))
        {
            At[i+1] = At[i];
            i=i-1;
        }
        At[i+1] = key;
    }
}

int iterative_binarysearch(int *At,int v,int low,int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (v==At[mid])
            return mid;
        else if (v > At[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return NULL;
}

int recursive_binarysearch(int *At,int v,int low,int high)
{
    int mid;
    if (low > high)
        return NULL;
    mid = (low+high)/2;
    if (v == At[mid])
            return mid;
        else if (v > At[mid])
            return recursive_binarysearch(At,v,mid+1,high);
        else
            return recursive_binarysearch(At,v,low,mid-1);
}
