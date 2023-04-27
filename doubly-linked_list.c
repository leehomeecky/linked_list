#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* previous; 
};

void insert(struct Node** head, int data, int position);
void print(struct Node* head);


int main(int argc, char const *argv[])
{
    struct Node* head = NULL;
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
    return 0;
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


void insert(struct Node** head, int data, int position)
{
    struct Node* temp = (struct Node*)malloc(sizeof(int));
    struct Node* temp1 = *head;
    temp->data = data;
    if (position == 1)
    {
        temp->next = *head;
        temp->previous = NULL;
        if(*head != NULL)temp1->previous = temp;
        *head = temp;
    }
    else
    {
        for (int i = 0; i < position - 2; i++)
        {
            /* code */
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}