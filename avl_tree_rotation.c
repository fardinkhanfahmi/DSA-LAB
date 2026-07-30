#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *l;
    struct Node *r;
    int h;
} Node;

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(Node *n)
{
    if (n == NULL)
        return 0;

    return n->h;
}

Node *create(int v)
{
    Node *node = malloc(sizeof(Node));

    node->val = v;
    node->l = NULL;
    node->r = NULL;
    node->h = 1;

    return node;
}

int balance(Node *n)
{
    if (n == NULL)
        return 0;

    return height(n->l) - height(n->r);
}

Node *left_rotate(Node *x)
{
    Node *y = x->r;
    Node *temp = y->l;

    y->l = x;
    x->r = temp;

    x->h = max(height(x->l), height(x->r)) + 1;
    y->h = max(height(y->l), height(y->r)) + 1;

    return y;
}