#include "lists.h"

/**
 * find_listint_loop - Finds the start node of a loop in a linked list.
 *
 * @head: A pointer to the head of the linked list to search.
 *
 * Return: If a loop is found - A pointer to the node where the loop starts.
 *         Otherwise - NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_ptr = head;
	listint_t *fast_ptr = head;

	if (!head)
		return (NULL);

	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
		if (fast_ptr == slow_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}
			return (fast_ptr);
		}
	}

	return (NULL);
}

