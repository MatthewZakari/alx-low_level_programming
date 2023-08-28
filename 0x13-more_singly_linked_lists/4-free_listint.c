#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Frees a listint_t list.
 * @head: Pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
	listint_t *present; /*eclares a pointer named present */

	while (head != NULL) /* Iterates & free each node one by one*/
	{
		present = head; /*keep track of the current node we are about to free*/
		head = head->next;
		free(present);
	}
}

