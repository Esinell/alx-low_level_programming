#include "lists.h"

/**
*sum_listint - calculates the sum of all the data in a listint_t linked list
*@head: pointer to the first node of the linked list
*Return: the resulting sum of all the integers in the linked list
*/

	int sum_listint(listint_t *head)
{
	int result = 0;
	listint_t *current_node = head;

	while (current_node)
	{
	result += current_node->n;
	current_node = current_node->next;
	}

	return (result);
}

