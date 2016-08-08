#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

typedef struct {
    int *data ;
    int length;
    int heap_size;
} heap;

void MIN_HEAPIFY (heap *A, int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int smallest;
    if ((l< A->heap_size) && (A->data[l]<A->data[i]))
        smallest = l;
    else
        smallest = i;
    if ((r< A->heap_size) && (A->data[r]<A->data[smallest]))
        smallest = r;
    if (smallest != i)
    {
        int tmp = A->data[i];
        A->data[i] = A->data[smallest];
        A->data[smallest] = tmp;
        MIN_HEAPIFY(A, smallest);
    }
}

int HEAP_MINIMUM(heap *A)
{
    return A->data[0];
}

int HEAP_EXTRACT_MIN (heap *A)
{
    if(A->heap_size<0)
    {
        printf("Error: heap underflow");
        exit(0);
    }
    int min = A->data[0];
    A->data[0] = A->data[A->heap_size-1];
    A->heap_size = A->heap_size-1;
    MIN_HEAPIFY(A, 0);
    return min;
}

void HEAP_DECREASE_KEY (heap *A, int i, int key)
{
    if(key > A->data[i])
    {
         printf("Error: new key is larger than current key");
         exit(0);
    }
    A->data[i] = key;
    while (i > 0 && (A->data[PARENT(i)] > A->data[i]))
    {
        int tmp = A->data[i];
        A->data[i] = A->data[PARENT(i)];
        A->data[PARENT(i)] = tmp;
        i = PARENT(i);
    }
}

void MIN_HEAP_INSERT (heap *A, int key)
{
    if (A->length == A->heap_size) {
        printf("\n heap overflow");
        exit(0);
    }
    A->heap_size = A->heap_size + 1;
    A->data[ A->heap_size-1 ] = INT_MAX;
    HEAP_DECREASE_KEY(A, A->heap_size-1, key);
}

void intialize_heap(heap *A, int len)
{
    A->length = len;
    A->heap_size = 0;
    A->data = (int *)malloc((sizeof(int)) * len);
}

int main()
{
    heap A = {NULL,0,0};
    intialize_heap(&A,10);
    MIN_HEAP_INSERT(&A,143);
    MIN_HEAP_INSERT(&A,9);
    MIN_HEAP_INSERT(&A,7);
    MIN_HEAP_INSERT(&A,999);
    MIN_HEAP_INSERT(&A,37);
    MIN_HEAP_INSERT(&A,88);
    MIN_HEAP_INSERT(&A,222);
    MIN_HEAP_INSERT(&A,335);
    MIN_HEAP_INSERT(&A,66);
    MIN_HEAP_INSERT(&A,0);
    int k ;
    for(k=0; k < A.length;k++)
        printf("%d,",A.data[k]);
    printf("\n");
    //MIN_HEAP_INSERT(&A,0);
    //HEAP_DECREASE_KEY(&A,9,1000);
    printf("%d \n",HEAP_MINIMUM(&A));
    printf("%d \n",HEAP_EXTRACT_MIN(&A));
    printf("%d \n",HEAP_EXTRACT_MIN(&A));
    for(k=0; k < A.length;k++)
        printf("%d,",A.data[k]);
    return 0;
}

