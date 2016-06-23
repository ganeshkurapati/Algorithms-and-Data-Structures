#include <stdio.h>
#include <stdlib.h>
void selectionsort(int *At,int size);
int main()
{
    int k;
    int A[10]={143,9,7,999,37,88,222,335,66,0};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    selectionsort(A,sizeof(A) / sizeof(A[0]));
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    return 0;
}
void selectionsort(int *At, int size)
{
    int i,j,small,tmp;
    for(i=0;i<size-1;i++)
    {
        small=i;
        for(j=i+1;j<size;j++)
        {
            if( At[j] <= At[small] )
                small=j;
        }
        tmp = At[small];
        At[small] = At[i];
        At[i] = tmp;
    }

}

