#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to the pointer to the first node of the list.
 * @n: The integer to be added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *n_node = malloc(sizeof(listint_t));
	listint_t *present;

	if (n_node == NULL) /* Checks if memory allocation was successful */
	{
		return (NULL);
	}

	n_node->n = n;
	n_node->next = NULL;

	if (*head == NULL)
	{
		*head = n_node;
	}
	else
	{
		present = *head;
		while (present->next != NULL)
		{
			present = present->next;
		}
		present->next = n_node;
	}

	return (n_node);
}

