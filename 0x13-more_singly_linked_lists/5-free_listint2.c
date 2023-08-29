#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: A pointer to a pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *present; /* For traversing the list */
	listint_t *temp; /* temporarily hold the present node for freeing */

	if (head == NULL) /* checks if the input head pointer is NULL */
	{
		return;
	}

	present = *head; /* starting point for traversing the list */

	while (present != NULL)
	{
		temp = present;
		present = present->next; /* updates &  point to the next node in the list */
		free(temp);
	}

	*head = NULL;
}

