#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1;
void push(int value)
{
    if(top == SIZE - 1)
    return;
    stack[++top] = value;
}
void pop()
{
    if (top == -1)
    return;
    top--;
}
void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d ",stack[i]);
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    pop();
    display();
    return 0;
}
