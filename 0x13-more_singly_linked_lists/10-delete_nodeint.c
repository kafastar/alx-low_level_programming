#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index of a listint_t list.
 * @head: Double pointer to the head node of the list.
 * @index: Index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	int i;
	listint_t *current, *tmp;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	current = *head;
	for (i = 0; current != NULL && i < (int)index - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL)
		return (-1);

	tmp = current->next;
	current->next = current->next->next;
	free(tmp);
	return (1);
}
