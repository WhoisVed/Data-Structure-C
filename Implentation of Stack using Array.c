#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data)
{
    if(top == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

int pop()
{
    int value;
    if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek()
{
   if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top];
}

void print()
{
    int i;
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    for(i=top; i>=0; i--)
    printf("%d\n", stack_arr[i]);
    printf("\n");
}

int main()
{
    int choice, data;
    while(1)
    {
        printf("\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print the top element\n");
        printf("4. print all the element of the stack\n");
        printf("5. Quit\n");
        printf("Please Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

            case 2:
            data = pop();
            printf("Deleted Element is %d\n", data);
            break;

            case 3:
            printf("The topmost element of the stack is %d\n", peek());
            break;

            case 4:
            print();
            break;

            case 5:
            exit(1);

            default:
            printf("Wrong Choice\n");
        }
    }
    return 0;
}