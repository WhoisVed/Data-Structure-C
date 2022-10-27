#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node * ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//Insertion part
//case 1
struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

//case 2
struct Node * insertionAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

//case 3
struct Node * insertionAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

//case 4
struct Node * insertionAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

//Deletion part
//case 1
struct Node * deleteAtFirst(struct Node * head){
    struct Node * ptr = head;
    free (ptr);
    return head;
}

//case 2
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i = 0; i<index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

//case 3
struct Node * deletionAtLast(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//case 4
struct Node * deletionAtIndex(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q =q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int  main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 16;
    third->next = fourth;

    fourth->data = 22;
    fourth->next = NULL;

    printf("Linked List before insertion\n");
    linkedlistTraversal(head);

    head = insertionAfterNode(head, second, 12);
    printf("Linked list After insertion\n");
    linkedlistTraversal(head);

    printf("Linked list before Deletion\n");
    linkedlistTraversal(head);

    head = deleteAtIndex(head, 2);
    printf("Linked list After Deletion\n");
    linkedlistTraversal(head);

    return 0;
}
