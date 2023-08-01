#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Double pointer to the head node of the list.
 * Return: The head node's data (n), or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (0); /* Return 0 if the list is empty */

	temp = *head;
	data = temp->n;
	*head = temp->next;
	free(temp);

	return (data);
}
