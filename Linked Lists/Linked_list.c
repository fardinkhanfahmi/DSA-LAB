#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}
struct Node *head = NULL;
void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, value;
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
        scanf("%d", &value);
        insert(value);
    }
    display();
    return 0;
}
