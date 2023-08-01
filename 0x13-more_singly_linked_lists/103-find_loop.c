#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: The node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow = head;
	fast = head->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (fast == slow)
		{
			slow = head;
			while (slow != fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	return (NULL);
}
