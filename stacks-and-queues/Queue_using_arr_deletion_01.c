#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value)
{
    if(rear == SIZE - 1)
    return;
    if(front==-1)
    front = 0;
    queue[++rear] = value;
}
void dequeue()
{
    if(front == -1 || front > rear)
    return;
    front++;
}

void display()
{
    if(front == -1 || front > rear)
    return;
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",queue[i]);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    dequeue();
    display();
    return 0;
}
