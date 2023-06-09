#include <stdio.h>
#include <stdlib.h>

typedef struct {
        void *next;
        int data;
} Node;

Node *head = NULL;
Node *new = NULL;

// add node to list.
Node *addNode(int data)
{
    //two cases
    //if list is empty
    if (head == NULL)
    {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        head = new;
        new->next = NULL;
    }
    else
    {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        new->next = head;
        head = new;
    }
    return new;

     
}

// remove node from list
int removeNode(int data)
{
    Node *current = head;
    Node *prev = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current == head)
            {
                head = current->next;
                free(current);
                current = NULL;
            } else {
                prev->next = current->next;
                free(current);
                current = NULL;
            }
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}
// insert a node into a position in the list
Node *insertNode(int data, int position)
{
    Node *current = head;
    while (current != NULL && position != 0)
    {
        position--;
    }

    if (position != 0)
    {
        printf("Error occurred.\n");
        return NULL;
    }

    Node *new = malloc(sizeof(Node));
    if (new == NULL)
        return NULL;

    new->data = data;
    new->next = current->next;
    current->next = new;

    return new;
}

//print menu
void printList()
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }

    printf("NULL.\n");

    return;
}

void printMenu()
{
    printf("Select an option: \n");
    printf("\t1. Add a node to the list.\n");
    printf("\t2. Remove a node from the list.\n");
    printf("\t3. Insert a node to the list.\n");
    printf("\t4. Print list.\n");
    printf("\t5. Exit.\n");
    return;
}

int main(int argc, char **argv)
{
    int arg1 = 0; 
    int choice = 0;
    int arg2 = 0;
    while (choice != 5)
    {
        printMenu();
        int num_received = scanf("%d", &choice);
        if (num_received == 1 && choice > 0 && choice <= 4)
        {
            switch(choice)
            {
                case 1:
                    //add operation
                    printf("Enter data you would like to add to list. \n");
                    scanf("%d", &arg1);
                    new = addNode(arg1);
                    break;
                case 2:
                    //remove operation
                    printf("Enter data you would like to remove from list. \n");
                    scanf("%d", &arg1);
                    int success = removeNode(arg1);
                    break;
                case 3:
                    //insert operation
                    printf("Enter data you would like to insert into list. \n");
                    scanf("%d", &arg1);
                    printf("What position");
                    scanf("%d", &arg2);
                    Node *new = insertNode(arg1, arg2);
                    if (insertNode == NULL)
                    {
                        printf("Failed to insert node.\n");
                    }
                    break;
                case 4:
                    // print list
                    printList();
                    break;
                case 5:
                    //Exit.
                    break;
            }
        }
    }
        return 0;
}
