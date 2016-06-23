#include <stdio.h>
#include <stdlib.h>
void bubblesort(int *At,int size);
int main()
{
    int k;
    int A[10]={143,9,7,999,37,88,222,335,66,0};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    bubblesort(A,sizeof(A) / sizeof(A[0]));
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    return 0;
}
void bubblesort(int *At, int size)
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

