#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a node at a specified position
 * @head: A pointer to a pointer to the head of the list.
 * @idx: The index at which the new node should be inserted.
 * @n: The data to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *n_node;
	listint_t *present = *head;
	unsigned int i;

	/* Create a new node */
	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
	{
		return (NULL);
	}
	n_node->n = n;

	/* If idx is 0, insert at the beginning */
	if (idx == 0)
	{
		n_node->next = *head;
		*head = n_node;
		return (n_node);
	}

	/* Traverse the list to find the node at position (idx - 1) */
	for (i = 0; present != NULL && i < (idx - 1); i++)
	{
		present = present->next;
	}

	/* If 'present' is NULL or 'idx' exceeds the list length, return NULL */
	if (present == NULL)
	{
		return (NULL);
	}

	/* Insert the new node after the present node */
	n_node->next = present->next;
	present->next = n_node;

	return (n_node);
}

