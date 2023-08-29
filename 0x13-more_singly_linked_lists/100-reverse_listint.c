#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: Pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *present = *head;
	listint_t *next;

	while (present != NULL)
	{
		next = present->next;
		present->next = previous;
		previous = present;
		present = next;
	}

	*head = previous; /* Update the head pointer to the new head. */
	return (previous);
}

