#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head node of the list.
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t node_count = 0; /* Initialize the counter for the number of nodes. */

	while (h != NULL) /* Traverse the list until (NULL is encountered). */
	{
		printf("%d\n", h->n); /* Print the integer value of the current node. */
		h = h->next; /* Move to the next node in the list. */
		node_count++; /* Increment the node counter. */
	}

	return (node_count); /* Return the total number of nodes in the list. */
}
