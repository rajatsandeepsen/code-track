// write a linked list program in c to insert, delete and search an element in a linked list using functions. 1. Insert a node at the beginning of the linked list. 2. Insert a node at the end of the linked list. 3. Insert a node at the nth position of the linked list. 4. Delete a node from the beginning of the linked list. 5. Delete a node from the end of the linked list. 6. Delete a node from the nth position of the linked list. 7. Search an element in the linked list. 8. Display the linked list. 9. Exit. 1. Insert a node at the beginning of the linked list. 2. Insert a node at the end of the linked list. 3. Insert a node at the nth position of the linked list. 4. Delete a node from the beginning of the linked list. 5. Delete a node from the end of the linked list. 6. Delete a node from the nth position of the linked list. 7. Search an element in the linked list. 8. Display the linked list. 9. Exit. 1. Insert a node at the beginning of the linked list. 2. Insert a node at the end of the linked list. 3. Insert a node at the nth position of the linked list. 4. Delete a node from the beginning of the linked list. 5. Delete a node from the end of the linked list. 6. Delete a node from the nth position of the linked list. 7. Search an element in the linked list. 8. Display the linked list. 9. Exit. 1. Insert a node at the beginning of the linked list. 2. Insert a node at the end of the linked list. 3. Insert a node at the nth position of the linked list. 4. Delete a node from the beginning of the linked list. 5. Delete a node from the end of the linked list. 6. Delete a node from the nth position of the linked list. 7. Search an element in the linked list. 8. Display the linked list. 9. Exit. 1. Insert a node at the beginning of the linked list. 2. Insert a node at the end of the linked list. 3. Insert a node at the nth position of the linked

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// display the list
void printList()
{
    struct node *ptr = head;
    printf("\n[ ");

    // start from the beginning
    while (ptr != NULL)
    {
        printf("(%d) ", ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}

// insert link at the first location
void insertFirst(int data)
{
    // create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->data = data;

    // point it to old first node
    link->next = head;

    // point first to new first node
    head = link;
}

// delete first item
struct node *deleteFirst()
{

    // save reference to first link
    struct node *tempLink = head;

    // mark next to first link as first
    head = head->next;

    // return the deleted link
    return tempLink;
}

// is list empty
// bool isEmpty()
// {
//     return head == NULL;
// }

int length()
{
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }

    return length;
}

// delete from last position
struct node *deleteLast()
{
    struct node *current = head;
    struct node *previous = NULL;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    // at this point, current points to the last element
    // and previous points to the second last element
    previous->next = NULL;
    return current;
}

// insert from last position
void insertLast(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;

    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = link;
}

// delete from nth position
struct node *deleteNth(int n)
{
    struct node *current = head;
    struct node *previous = NULL;

    int i;
    for (i = 0; i < n; i++)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    return current;
}