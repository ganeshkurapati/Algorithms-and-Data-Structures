#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct
{
    int left;
    int right;
    int sum;
} sub_array;

sub_array FIND_MAXIMUM_SUBARRAY (int *At, int low, int high);

int main()
{
    int k ;
    sub_array tmp;
    int A[11]={-5,9,7,999,37,88,222,335,-1,0,-1};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    tmp = FIND_MAXIMUM_SUBARRAY( A,0,(lengthof_A-1));
    printf("left: %d,right: %d,sum: %d",tmp.left, tmp.right, tmp.sum);
    return 0;
}
sub_array FIND_MAXIMUM_SUBARRAY (int *At, int low, int high)
{
    sub_array max_subarray = {0,0,INT_MIN};
    int brute_sum, i, j;
    for(i = low; i < high; i++)
    {
        brute_sum = 0;
        for(j = i; j < high ; j++)
        {
            brute_sum += At[j];
            if(brute_sum > max_subarray.sum)
            {
                max_subarray.left = i;
                max_subarray.right = j;
                max_subarray.sum = brute_sum;
            }
        }
    }
    return max_subarray;
}
