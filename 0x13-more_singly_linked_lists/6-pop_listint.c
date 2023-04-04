#include "lists.h"

/**
 * pop_listint - deletes the head node of..
 * a linked list and returns its data
 * @head: pointer to the first element of the linked list
 *
 * Return: the data inside the deleted node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	/* if the list is empty, return 0 */
	if (head == NULL || *head == NULL)
		return (0);

	/* store the data in the head node */
	int data = (*head)->n;

	/* update the head pointer to point to the next node */
	listint_t *temp = *head;
	*head = (*head)->next;

	/* free the memory of the deleted node */
	free(temp);

	/* return the stored data */
	return (data);
}

