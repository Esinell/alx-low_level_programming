#include "lists.h"

/**
 * listint_len - prints all the elements of a list
 * @h: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
size_t count = 0;
const listint_t *current;

	for (current = h; current; current = current->next)
	{
	count++;
	}

	return (count);
}

