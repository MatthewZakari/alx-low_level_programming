#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: A pointer to the pointer to the head of the list.
 * @n: The integer to add to the list.
 * Return: The address of the new element, or NULL if it failed.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *n_node = malloc(sizeof(listint_t));

	if (n_node == NULL)
	{
		return (NULL); /*Return NULL if memory allocation fails*/
	}

	n_node->n = n; /* set the data of the new node*/
	n_node->next = *head; /* Make the new node points to the current head */
	*head = n_node; /* Update the head to point to the new node */

	return (n_node); /* Return the address of the new element*/
}

