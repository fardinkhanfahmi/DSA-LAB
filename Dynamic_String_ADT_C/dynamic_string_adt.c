#include <stdio.h>
#include <stdlib.h>

typedef struct S
{
    char *str;
    int size, n;
} S;

void push_back(S *s, char c)
{
    if (s->size == s->n)
    {
        s->str = (char *)realloc(s->str, sizeof(char) * 2 * s->size);
        s->size *= 2;
    }

    s->str[s->n++] = c;
}

void create(S *s, char c[])
{
    int sz = 0;

    while (c[sz] != '\0')
        sz++;

    s->str = (char *)malloc(sizeof(char) * (2 * sz + 1));
    s->size = 2 * sz + 1;
    s->n = 0;

    for (int i = 0; i < sz; i++)
        push_back(s, c[i]);
}

void pop_back(S *s)
{
    if (s->n == 0)
        return;

    s->n--;
}

int get_size(S *s)
{
    return s->n;
}

char at_index(S *s, int index)
{
    return s->str[index];
}

void clear(S *s)
{
    s->n = 0;
}

void concat(S *main_string, S *pattern)
{
    for (int i = 0; i < pattern->n; i++)
    {
        push_back(main_string, pattern->str[i]);
    }
}

void display(S *s)
{
    for (int i = 0; i < s->n; i++)
    {
        printf("%c", s->str[i]);
    }

    printf("\n");
}

void insert_at(S *s, char c, int index)
{
    if (index < 0 || index > s->n)
        return;

    push_back(s, c);

    for (int i = s->n - 1; i > index; i--)
    {
        s->str[i] = s->str[i - 1];
    }

    s->str[index] = c;
}

void delete_at(S *s, int index)
{
    if (index < 0 || index >= s->n)
        return;

    for (int i = index; i < s->n - 1; i++)
    {
        s->str[i] = s->str[i + 1];
    }

    s->n--;
}

void replace_at(S *s, char c, int index)
{
    if (index < 0 || index >= s->n)
        return;

    s->str[index] = c;
}

int find_substring(S *s, S *pat)
{
    int n = s->n;
    int m = pat->n;

    if (m > n || m == 0)
        return -1;

    for (int i = 0; i <= n - m; i++)
    {
        int j;

        for (j = 0; j < m; j++)
        {
            if (s->str[i + j] != pat->str[j])
                break;
        }

        if (j == m)
            return i;
    }

    return -1;
}

void Free(S *s)
{
    if (s->str)
    {
        free(s->str);
        s->str = NULL;
    }

    s->size = 0;
    s->n = 0;
}

int main()
{
    S s1, s2;

    create(&s1, "Fardin");
    create(&s2, "Khan");

    printf("Original String: ");
    display(&s1);

    concat(&s1, &s2);

    printf("After Concatenation: ");
    display(&s1);

    insert_at(&s1, ' ', 6);

    printf("After Insert: ");
    display(&s1);

    delete_at(&s1, 6);

    printf("After Delete: ");
    display(&s1);

    printf("Substring index is: %d\n", find_substring(&s1, &s2));

    Free(&s1);
    Free(&s2);

    return 0;
}
