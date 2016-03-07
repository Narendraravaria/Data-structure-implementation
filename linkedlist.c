#include <stdio.h>
#include <stdlib.h>

// insert
// insertLast
// remove
// print
// size
// isEmpty


typedef struct node {
    int num;
    struct node *next;
} node;

void insertFirst(node **, int);
void insertLast(node **, int);
int isEmpty(node *);
void print(node *);
void removeFirst(node **);
void removeElement(node **, int);

int main()
{
    node *head = NULL;
    //head = malloc(sizeof(node));     
    printf("Is linked list Empty? %d\n", isEmpty(head));
    
    //head->num = 10;
    //head->next = NULL;
    insertFirst(&head, 30);
    insertFirst(&head, 20);
    insertFirst(&head, 10);
    print(head);
    
    insertLast(&head,40);
    print(head);
    
    removeFirst(&head);
    print(head);
    
    removeElement(&head, 30);
    print(head);
    
    
    removeElement(&head, 20);
    print(head);
    
    
    removeElement(&head, 40);
    print(head);
    
    insertFirst(&head, 100);
    print(head);
    
    insertFirst(&head, 100);
    print(head);
    
    insertLast(&head, 100);
    print(head);
}

int isEmpty(node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}


void insertFirst(node **head, int val)
{   //*head points to content of head
    node *curr;
    curr = malloc(sizeof(node));    //MEMORY CREATION
    
    curr->num = val;
    curr->next = *head;
    *head = curr;
}


void insertLast(node **head, int val)
{
    if(*head == NULL)
    {
        insertFirst(head, val);
        return 0;
    }
    node *curr = *head;
    
    while (curr->next !=NULL)
    {
        curr = curr->next;
    }   
    
    curr->next = malloc(sizeof(node));    //MEMORY CREATION
    curr->next->num = val;
    curr->next->next =NULL;
}


void removeFirst(node **head)
{
    if((*head) == NULL)
    {
        printf("Linked list is Empty\n");
    }
    node *removed = *head;
    int val = removed->num;
    
    *head = (*head)->next;
    free(removed);
}


void removeElement(node **head, int val)
{
    if(val == (*head)->num)
    {
        return removeFirst(&(*head));
    }
    
    node *curr = *head;
    node *prev;
    while (curr != NULL )   //search for an element in linked list
    {
        if(curr->num == val)
        {
            prev->next = curr->next;
            printf("value %d removed succesfully from Linked List\n",val);
            free(curr);
            break;
        }
        
        prev = curr;
        curr = curr-> next;
    }
    
    if(curr == NULL)    //element not found
    {
        printf("Linked List does not have value %d\n", val);
    }
    
}


void print(node *head)
{
    if(head != NULL)
    {
        node *curr = head;
        //node *prev;
        while (curr->next != NULL)
        {
            printf("%d -> ", curr->num);
            curr = curr->next;
        }
        printf("%d\n",curr->num);
    }
    else
    {
        printf("Empty Linked List\n");
    }
    
}
