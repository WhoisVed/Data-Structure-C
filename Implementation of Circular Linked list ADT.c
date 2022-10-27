#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=head);
}

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next != head)
    {
        p = p->next;
    
    }

    //At this point P points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;

}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocate memeory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //Link First and Second nodes 
    head->data = 1;
    head->next = second;

    //Link Second and Third nodes
    second->data = 4;
    second->next = third;

    //Link Third and Fourth nodes
    third->data = 7;
    third->next = fourth;

    //Terminate the list at fourth node
    fourth->data = 13;
    fourth->next = head;

    printf("Circular Linked list before Insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 3);
    printf("Circular Linked list after Insertion\n");
    linkedListTraversal(head);

    return 0;

}
