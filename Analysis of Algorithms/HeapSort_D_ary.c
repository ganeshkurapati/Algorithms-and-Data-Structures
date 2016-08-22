#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define PARENT(i, d) ((i - 1) / d)
#define CHILD(i, d, c) (d * i + c + 1)

typedef struct {
    int *data;
    int length;
    int heap_size;
    int child_no;
} heap;

void MAX_HEAPIFY (heap *A, int i)
{
    int largest = i,k,child;
    for(k =0;k < A->child_no;k++)
    {
        child = CHILD(i, A->child_no, k);
        if ((child < A->heap_size) && (A->data[child]>A->data[largest]))
            largest = child;
    }
    if (largest != i)
    {
        int tmp = A->data[i];
        A->data[i] = A->data[largest];
        A->data[largest] = tmp;
        MAX_HEAPIFY(A, largest);
    }
}

int HEAP_MAXIMUM(heap *A)
{
    return A->data[0];
}

int HEAP_EXTRACT_MAX (heap *A)
{
    if(A->heap_size<0)
    {
        printf("Error: heap underflow");
        exit(0);
    }
    int max = A->data[0];
    A->data[0] = A->data[A->heap_size-1];
    A->heap_size = A->heap_size-1;
    MAX_HEAPIFY(A, 0);
    return max;
}

void HEAP_INCREASE_KEY (heap *A, int i, int key)
{
    if(key < A->data[i])
    {
         printf("Error: new key is smaller than current key");
         exit(0);
    }
    while (i > 0 && (A->data[PARENT(i, A->child_no)] < key))
    {
        A->data[i] = A->data[PARENT(i, A->child_no)];
        i = PARENT(i, A->child_no);
    }
    A->data[i] = key;
}

void MAX_HEAP_INSERT (heap *A, int key)
{
    if (A->length == A->heap_size) {
        printf("\n heap overflow");
        exit(0);
    }
    A->heap_size = A->heap_size + 1;
    A->data[ A->heap_size-1 ] = INT_MIN;
    HEAP_INCREASE_KEY(A, A->heap_size-1, key);
}

void intialize_heap(heap *A, int len)
{
    A->length = len;
    A->heap_size = 0;
    A->data = (int *)malloc((sizeof(int)) * len);
}

int main()
{
    heap A = {NULL,0,0,3};
    intialize_heap(&A,10);
    MAX_HEAP_INSERT(&A,143);
    MAX_HEAP_INSERT(&A,9);
    MAX_HEAP_INSERT(&A,7);
    MAX_HEAP_INSERT(&A,999);
    MAX_HEAP_INSERT(&A,37);
    MAX_HEAP_INSERT(&A,88);
    MAX_HEAP_INSERT(&A,222);
    MAX_HEAP_INSERT(&A,335);
    MAX_HEAP_INSERT(&A,66);
    MAX_HEAP_INSERT(&A,0);
    int k ;
    for(k=0; k < A.length;k++)
        printf("%d,",A.data[k]);
    printf("\n");
    //MAX_HEAP_INSERT(&A,0);
    //HEAP_INCREASE_KEY(&A,8,10);
    //printf("%d \n",HEAP_MAXIMUM(&A));
    printf("%d \n",HEAP_EXTRACT_MAX(&A));
    printf("%d \n",HEAP_EXTRACT_MAX(&A));
    for(k=0; k < A.length;k++)
        printf("%d,",A.data[k]);
    return 0;
}
