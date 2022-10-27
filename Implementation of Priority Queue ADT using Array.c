#include <stdio.h>
#include <conio.h>

struct priorityqueue
{
    int ele;
    int priority;
}pq[5];
int rear = -1; 

int isEmpty();
int isFull();
void insert(int, int);
int gethighestpriority();
int deletehighestpriority();
void display();

int main()
{
    int ch, p, ele;
    do 
    {
        printf("1. Insert\n2. Get Highest Prioriity\n3. Delete Highest Priority\n4. Display\n5. Exit\n");
        printf("Enter Your Choice: \n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                if(isFull())
                    printf("Priority Queue is Full\n");
                else{
                    printf("Enter Element to Insert: \n");
                    scanf("%d", &ele);
                    printf("Enter Priority: \n");
                    scanf("%d", &p);
                    void insert(int ele, int p);
                }
                break;
                case 2:
                    if(isEmpty())
                        printf("Priority Queue is Empty\n");
                    else{
                        p = gethighestpriority();
                        printf("Highest Priority = %d", p);
                    }
                break;
                case 3:
                    if(isEmpty())
                        printf("Priority Queue is Empty\n");
                    else
                    {
                        ele = deletehighestpriority();
                        printf("%d is Deleted", ele);
                    }
                break;
                case 4:
                    if(isEmpty())
                        printf("Priority Queue is Empty\n");
                    else
                         display();
                break;
        }
    }while(ch!=5);
}

int isEmpty()
{
    if(rear == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear == 4)
        return 1;
    else
        return 0;
}

void insert(int ele, int p)
{
    rear = rear + 1;
    pq[rear].ele = ele;
    pq[rear].priority = p;
}

int gethighestpriority()
{
    int i, p = -1;
    if(!isEmpty())
    {
        for(i=0;i<=rear;i++)
        {
            if(pq[i].priority>p)
                p=pq[i].priority;
        }
    }
    return p;
}

int deletehighestpriority()
{
    int i, j, p, ele;
    p = gethighestpriority();
    for(i=0;i<=rear;i++)
    {
        if(pq[i].priority==p)
        {
            ele=pq[i].ele;
            break;
        }
    }
    if(i<rear)
    {
        for(j=1;j<rear;j++)
        {
            pq[j].ele = pq[j+1].ele;
            pq[j].priority = pq[j+1].priority;
        }
    }
    rear = rear - 1;
    return ele;
}

void display()
{
    int i;
        printf("Priority Queue: \n");
    for(i=0;i<=rear;i++)
        printf("ele = %d - priority = %d", pq[i].ele, pq[i].priority);
}

