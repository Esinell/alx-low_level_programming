#include "lists.h"

/**
 * free_listint_safe - Frees a linked list of integers, even if it contains
 *                     a loop.
 * @head: A pointer to the first node of the list to be freed.
 *
 * Return: The number of nodes in the list that was freed.
 */
size_t free_listint_safe(listint_t **head)
{
	size_t node_count = 0;
	int address_diff;
	listint_t *current_node, *next_node;

	if (!head || !*head)
		return (0);

	while (*head)
	{
		address_diff = *head - (*head)->next;

		if (address_diff > 0)
		{
			current_node = *head;
			next_node = (*head)->next;
			free(current_node);
			*head = next_node;
			node_count++;
		}
		else
		{
			free(*head);
			*head = NULL;
			node_count++;
			break;
		}
	}

	*head = NULL;
	return (node_count);
}

