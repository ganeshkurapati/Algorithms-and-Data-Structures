#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct
{
    int left;
    int right;
    int sum;
} sub_array;

sub_array FIND_MAXIMUM_SUBARRAY_LINEAR(int *At, int low, int high);

int main()
{
    int k ;
    sub_array tmp;
    int A[11]={-5,9,7,999,37,88,222,335,-1,0,-1};
    for(k=0; k < (sizeof(A) / sizeof(A[0]));k++)
        printf("%d,",A[k]);
    printf("\n");
    int lengthof_A = sizeof(A) / sizeof(A[0]);
    tmp = FIND_MAXIMUM_SUBARRAY_LINEAR( A,0,(lengthof_A-1));
    printf("left: %d,right: %d,sum: %d",tmp.left, tmp.right, tmp.sum);
    return 0;
}
sub_array FIND_MAXIMUM_SUBARRAY_LINEAR(int *At, int low, int high)
{
    sub_array max_subarray = {0,0,At[low]};
    int linear_sum =0, tmp_left =0 , i;
    for(i = low; i <= high; i++)
    {
        linear_sum = ((At[i]) > (linear_sum+At[i]) ? (At[i]) : (linear_sum+At[i]));
        if(linear_sum > max_subarray.sum)
        {
            max_subarray.sum = linear_sum;
            max_subarray.right = i;
            max_subarray.left = tmp_left;
        }
        if(linear_sum == At[i])
            tmp_left = i;
    }
    return max_subarray;
}
