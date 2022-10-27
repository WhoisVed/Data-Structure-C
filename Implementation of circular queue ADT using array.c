#include <stdio.h>

int isFull();
int isEmpty();
void enqueue();
void dequeue();
void display();

int cq[5] = {0};
int rear = -1;
int front = -1;

int main()
{
    int ch;
    int ele;
    do 
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter Your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                if(isFull())
                    printf("Queue is Full\n");
                else
                {
                    printf("Enter Element To Enqueue: \n");
                    scanf("%d", &ele);
                    void enqueue (int ele);
                }
                break;

            case 2:
                if(isEmpty())
                    printf("Queue is Empty\n");
                else
                {
                    printf("Enter Element To Dequeue: \n");
                    scanf("%d", &ele); 
                    dequeue();                  
                }
                break;

            case 3:
                if(isEmpty())
                    printf("Queue is Empty\n");
                else
                    display();
                break;                
        }
    }
    while(ch!=5);
}

int isFull()
{
    if(front == 0 && rear == 4) 
        return 1;
    else if(rear + 1 == front)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int ele)
{
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == 4)
        rear = 0;
    else
        rear = rear + 1;
    cq[rear] = ele;
}

void dequeue()
{
    int ele;
    ele = cq[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front == 4)
        front = 0;
    else
        front = front + 1;
}

void display()
{
    int i;
    printf("front = %d and rear = %d\n",front,rear);
    if(rear>front)
    {
        for(i=front;i<=rear;i++)
            printf("%d", cq[i]);
    }
    else{
        for(i=front;i<=4;i++)
            printf("%d", cq[i]);
        for(i=0;i<=rear;i++)
             printf("%d", cq[i]);   
    }
}
