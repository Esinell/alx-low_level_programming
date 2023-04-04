#include "lists.h"
#include <stdlib.h>

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t get_looped_list_len(const listint_t *head)
{
    listint_t *slow_ptr = (listint_t *)head, *fast_ptr = (listint_t *)head;
    size_t count = 0;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            count = 1;
            while (slow_ptr->next != fast_ptr)
            {
                slow_ptr = slow_ptr->next;
                count++;
            }
            return count;
        }
    }

    return 0;
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0, loop_len = 0;
    listint_t **nodes = NULL, *tmp = (listint_t *)head;

    loop_len = get_looped_list_len(head);

    if (loop_len > 0)
        count = loop_len;
    else
    {
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
    }

    nodes = malloc(sizeof(listint_t *) * count);
    if (nodes == NULL)
        exit(98);

    tmp = (listint_t *)head;
    for (size_t i = 0; i < count; i++)
    {
        nodes[i] = tmp;
        tmp = tmp->next;
    }

    for (size_t i = 0; i < count; i++)
    {
        printf("[%p] %d\n", (void *)nodes[i], nodes[i]->n);
        if (i == count - 1 && loop_len > 0)
            printf("-> [%p] %d\n", (void *)nodes[i]->next, nodes[i]->next->n);
    }

    free(nodes);
    return count;
}

