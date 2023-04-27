#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void print(struct Node* head);
void insert(struct Node** head, int x, int position);
void delete(struct Node** head, int position);
void revers(struct Node** head);
void recurs_revers(struct Node** head, struct Node* previous);

int main(int argc, char const *argv[])
{
    struct Node* head;
    head = NULL;
    /* code */
    for (int i = 1; i < argc; i++)
    {
        /* code */
        insert(&head, atoi(argv[i]), 1);
    }

    insert(&head, 7, 1);
    insert(&head, 5, 1);
    insert(&head, 10, 1);
    insert(&head, 3, 3);
    insert(&head, 100, 3);
    insert(&head, 150, 3);
    insert(&head, 500, 7);
    print(head);
    delete(&head, 5);
    delete(&head, 1);
    print(head);
    revers(&head);
    print(head);
    recurs_revers(&head, head);
    print(head);
    
    return 0;
}

void insert(struct Node** head, int x, int position)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp2 = *head;
    temp1 -> data = x;

if (position == 1)
{
    /* code */
    temp1 -> next = *head;
    *head = temp1;
}
else
{
    for (int i = 0; i < (position - 2); i++)
        temp2 = temp2 -> next;

    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    
}

    
}


void print(struct Node* head)
{
   
        /* code */
        printf("%s", "Data is : ");
        while (head != NULL)
        {
            /* code */
            printf("%d, ", head -> data);

            head = head -> next;
        }
    putchar('\n');
    
}

void delete(struct Node** head, int position)
{
    struct Node* temp1 = *head;
    struct Node* temp2;
    if (position ==1)
    {
        *head = temp1 -> next;

        free(temp1); 
    }
    else
    {
        for (int i = 0; i < position - 2; i++)
            temp1 = temp1 -> next;

        temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        free(temp2);
        
    }
}


void revers(struct Node** head)
{
    struct Node *current, *previous, *next;
    current = *head;
    previous = NULL;

    while (current != NULL)
    {
        /* code */
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;

    }
    *head = previous;

    
}


void recurs_revers(struct Node** head, struct Node* previous)
{
    // struct Node* temp = *head;
    if (previous->next == NULL)
    {
        *head = previous;
        return;
    }
    recurs_revers(head, previous->next);
    struct Node* current = previous->next;
    current->next = previous;
    previous->next = NULL;
    
}
