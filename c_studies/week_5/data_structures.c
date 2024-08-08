#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    // Start the loop from 1 to skip argv[0]
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        // Allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        // Assign the number and point to the current list
        n->number = number;
        n->next = list;

        // Update the head of the list
        list = n;
    }

    // Print the numbers in the list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i ", ptr->number); // Add a space for readability
        ptr = ptr->next;            // Move to the next node
    }

    // Free the memory allocated for the list
    ptr = list;
    while (ptr != NULL)
    {
        node *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

    return 0;
}
