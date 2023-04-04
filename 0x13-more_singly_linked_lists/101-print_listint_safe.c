#include "lists.h"
#include <stdio.h>

size_t get_looped_list_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

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
    const listint_t *slow_ptr, *fast_ptr;
    size_t count = 1;

    if (head == NULL || head->next == NULL)
        return (0);

    slow_ptr = head->next;
    fast_ptr = (head->next)->next;

    while (fast_ptr)
    {
        if (slow_ptr == fast_ptr)
        {
            slow_ptr = head;
            while (slow_ptr != fast_ptr)
            {
                count++;
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }

            slow_ptr = slow_ptr->next;
            while (slow_ptr != fast_ptr)
            {
                count++;
                slow_ptr = slow_ptr->next;
            }

            return (count);
        }

        slow_ptr = slow_ptr->next;
        fast_ptr = (fast_ptr->next)->next;
    }

    return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count, i = 0;

    count = get_looped_list_len(head);

    if (count == 0)
    {
        for (; head != NULL; count++)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
        }
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
        }

        printf("-> [%p] %d\n", (void *)head, head->n);
    }

    return (count);
}

