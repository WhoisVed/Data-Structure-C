#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr !=NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

//Case 2
struct Node * insertAtIndex(struct Node *head, int data, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

//Case 3
struct Node * insertAtEnd(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

//Case 4
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

//Deletion
//Case 1 : Deleting the First Element from Linked List
struct Node * deleteFirst(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//Case 2 : Deleting the element at given index from the linked list
struct Node * deleteAtIndex(struct Node * head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

//Case 3 : Deleting the last element
struct Node * deleteAtLast(struct Node * head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;    
    }

    p->next = NULL;
    free(q);
    return head;
}

//Case 4 : Deleting the element with a given value from the linked  list
struct Node * deleteAtValue(struct Node * head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //Link First and Second nodes 
    head->data = 3;
    head->next = second;

    //Link Second and Third nodes
    second->data = 5;
    second->next = third;

    //Link Third and Fourth nodes
    third->data = 8;
    third->next = fourth;

    //Terminate the list at the fourth node
    fourth->data = 12;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);

    head = insertAtEnd(head, 16 );
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    head = deleteAtValue(head, 8);
    printf("Linked list after deletion\n");
    linkedListTraversal(head);
    

    return 0;
}