#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Pointer to the head of the list.
 * @n: Integer to be stored in the new node.
 * Return: Address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	if (!head)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	/* Set the data of the new node */
	new_node->n = n;

	/* Set the next pointer of the new node to NULL */
	new_node->next = NULL;

	/* If the list is empty, new node becomes the head */
	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to find the last node */
	temp = *head;
	while (temp->next)
		temp = temp->next;

	/* Set the prev pointer of the new node to the last node */
	new_node->prev = temp;

	/* Update the next pointer of the last node to the new node */
	temp->next = new_node;

	return (new_node);
}
