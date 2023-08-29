#include "lists.h"
#include <stddef.h>

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *present = *h;
	listint_t *next;
	size_t size = 0;

	while (present != NULL)
	{
		next = present->next;
		free(present);
		size++;
		present = next;

		/* Detect and handle circular references */
		if (present == *h)
		{
			*h = NULL; /* Set the head to NULL to prevent further access */
			break;
		}
	}

	return (size);
}

