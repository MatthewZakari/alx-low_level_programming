#include "lists.h"

/**
 * sum_listint - Calculates the sum of 'n' in a listint_t linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The sum of all data values. If the list is empty, return 0.
 */
int sum_listint(listint_t *head)
{
	listint_t *present = head;
	int sum = 0;

	while (present != NULL)
	{
		sum += present->n;
		present = present->next;
	}

	return (sum);
}

