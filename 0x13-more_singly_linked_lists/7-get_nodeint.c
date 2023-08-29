#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to retrieve (starting at 0).
 *
 * Return: Pointer to the nth node or NULL if it doesn't exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *present = head;

	/* Traverse the list to the nth node */
	while (present != NULL)
	{
		if (count == index)
		{
			return (present);
		}
		present = present->next;
		count++;
	}

	/* If index is out of bounds, return NULL */
	return (NULL);
}
