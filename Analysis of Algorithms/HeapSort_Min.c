#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

typedef struct {
    int *data;
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

void BUILD_MIN_HEAP (heap *A)
{
    A->heap_size = A->length;
    int i;
    for(i = (int)((A->length/2)-1); i>=0; i--)
        MIN_HEAPIFY(A,i);
}

void HEAPSORT (heap *A)
{
    BUILD_MIN_HEAP(A);
    int i;
    for(i = A->length -1; i>=1; i--)
    {
        int tmp = A->data[0];
        A->data[0] = A->data[i];
        A->data[i] = tmp;
        A->heap_size = A->heap_size -1;
        MIN_HEAPIFY(A, 0);
    }
}

int main()
{
    heap *A;
    A->length = 11;
    int T[11] = {143,9,7,999,37,88,222,335,66,0,0};
    A->data = T;
    int k ;
    for(k=0; k < A->length;k++)
        printf("%d,",A->data[k]);
    printf("\n");
    HEAPSORT(A);
    for(k=0; k < A->length;k++)
        printf("%d,",A->data[k]);
    return 0;
}

