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
sub_array FIND_MAXIMUM_CROSSING_SUBARRAY(int *At, int low, int mid, int high);

int main()
{
    int k ;
    sub_array tmp;
    //int A[11]={-5,9,7,999,37,88,222,335,-1,0,-1};
    int A[1] = {-1};
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
    if(low == high)
    {
        sub_array result = {low, high, At[low]};
        return result;
    }
    else
    {
        int mid = (low + high)/2;
        sub_array left = FIND_MAXIMUM_SUBARRAY(At, low, mid);
        sub_array right = FIND_MAXIMUM_SUBARRAY(At, mid+1, high);
        sub_array cross = FIND_MAXIMUM_CROSSING_SUBARRAY(At, low, mid, high);
        if ((left.sum >= right.sum)&&(left.sum >= cross.sum))
            return left;
        else if ((right.sum >= left.sum)&&(right.sum >= cross.sum))
            return right;
        else
            return cross;
    }
}

sub_array FIND_MAXIMUM_CROSSING_SUBARRAY(int *At, int low, int mid, int high)
{
    sub_array cross;
    int left_sum = INT_MIN;
    int sum = 0;
    int i;
    for (i = mid; i>= low; i--)
    {
        sum += At[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            cross.left = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    int j = 0;
    for (j = mid+1; j<= high; j++)
    {
        sum += At[j];
        if(sum > right_sum)
        {
            right_sum = sum;
            cross.right = j;
        }
    }
    cross.sum = left_sum + right_sum;
    return cross;
}
