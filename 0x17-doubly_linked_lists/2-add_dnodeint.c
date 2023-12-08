#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: integer value for the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode;

	if (head == NULL)
		return (NULL);

	/* Allocate memory for the new node */
	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	/* Initialize the new node */
	newNode->n = n;
	newNode->prev = NULL;

	/* Update links */
	newNode->next = *head;
	if (*head != NULL)
		(*head)->prev = newNode;

	/* Update the head to point to the new node */
	*head = newNode;

	return (newNode);
}
