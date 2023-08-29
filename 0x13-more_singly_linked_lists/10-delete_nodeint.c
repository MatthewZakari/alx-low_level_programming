#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a given index in a linked list.
 * @head: A pointer to the head of the linked list.
 * @index: The index of the node to be deleted (starting from 0).
 *
 * Return: 1 if the node is successfully deleted, -1 if the deletion fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *previous = *head;
	listint_t *present = previous->next;
	unsigned int i = 1;

	if (*head == NULL)
	{
		return (-1); /* Invalid index or empty list */
	}

	/* Special case for deleting the head node */
	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	else
	{
		return (-1);
	}

	/* Traverse the list to find the node before the one to be deleted */
	while (present != NULL && i < index)
	{
		previous = present;
		present = present->next;
		i++;
	}

    /* If index is out of bounds, return -1 */
	if (i < index || present == NULL)
	{
		return (-1);
	}

	/* Update the previous node's next pointer to skip the node to be deleted */
	previous->next = present->next;
	free(present);
	return (1);
}

