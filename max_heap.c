#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size;
    int capacity;
} Heap;

Heap *create(int capacity)
{
    Heap *h = malloc(sizeof(Heap));

    h->capacity = capacity;
    h->size = 0;
    h->arr = malloc(capacity * sizeof(int));

    return h;
}

int parent(int i)
{
    return (i - 1) / 2;
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_up(Heap *h, int i)
{
    while (i != 0 && h->arr[parent(i)] < h->arr[i])
    {
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
}

void insert(Heap *h, int x)
{
    if (h->size == h->capacity)
        return;

    int i = h->size;

    h->arr[i] = x;
    h->size++;

    heapify_up(h, i);
}

void heapify_down(Heap *h, int i)
{
    int large = i;

    int l = left(i);
    int r = right(i);

    if (l < h->size && h->arr[l] > h->arr[large])
        large = l;

    if (r < h->size && h->arr[r] > h->arr[large])
        large = r;

    if (large != i)
    {
        swap(&h->arr[i], &h->arr[large]);
        heapify_down(h, large);
    }
}

int delete_max(Heap *h)
{
    if (h->size == 0)
        return -1;

    int ans = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapify_down(h, 0);

    return ans;
}

void print_heap(Heap *h)
{
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->arr[i]);

    printf("\n");
}

int main()
{
    Heap *h = create(10);

    insert(h, 10);
    insert(h, 20);
    insert(h, 15);
    insert(h, 40);
    insert(h, 50);
    insert(h, 100);

    print_heap(h);

    printf("Max = %d\n", delete_max(h));

    print_heap(h);

    free(h->arr);
    free(h);

    return 0;
}