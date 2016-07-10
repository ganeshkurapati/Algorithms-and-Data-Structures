#include <stdio.h>
#include <stdlib.h>
void bubblesort(int *At,int size);
int main()
{
    int k;
    int A[11]={143,9,7,999,37,88,222,335,66,0,0};
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
    int i,j,temp;
    for(i=0;i<size-1;i++)
    {
        for(j=size-1;j>=i+1;j--)
        {
            if( At[j] < At[j-1] )
            {
                temp = At[j];
                At[j] = At[j-1];
                At[j-1] = temp;
            }

        }
    }

}

