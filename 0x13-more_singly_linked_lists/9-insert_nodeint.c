#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts new node at a given position in the list.
 * @head: Double pointer to the head node of the list.
 * @idx: Index where the new node should be added. Index starts at 0.
 * @n: Data (n) to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int count = 0;
	listint_t *new_node, *current;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current != NULL)
	{
		if (count == idx - 1)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}
		count++;
		current = current->next;
	}

	free(new_node); /* If it is not possible to add the new node, free it */
	return (NULL);
}
