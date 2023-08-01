#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Double pointer to the head node of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next_node;

	if (h == NULL)
		return (0);

	current = *h;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		count++;

		if (current >= next_node)
		{
			*h = NULL;
			break;
		}

		current = next_node;
	}

	return (count);
}
