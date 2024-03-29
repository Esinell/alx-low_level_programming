#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts ...
 * a new node at a given index in a linked list.
 * @head: A pointer to the first node in the list.
 * @idx: The index where the new node should be added.
 * @n: The data to be inserted in the new node.
 *
 * Return: A pointer to the new node if successful, otherwise NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node;
	listint_t *temp_node = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; temp_node && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new_node->next = temp_node->next;
			temp_node->next = new_node;
			return (new_node);
		}
		else
			temp_node = temp_node->next;
	}

	return (NULL);
}

