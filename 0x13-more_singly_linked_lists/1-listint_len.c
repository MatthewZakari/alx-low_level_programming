#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list
 * @h: A pointer to the head of the list
 *
 * Return: The number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t compute = 0; /* Initialize a counter to 0 */

	while (h != NULL)
	{
		compute++; /* Increment the counter for each node */
		h = h->next; /* Move to the next node */
	}

	return (compute); /* Return the final count */
}
