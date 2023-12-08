#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a linked list
 * @head: double pointer to the head of the linked list
 * @index: index of the node to be deleted, starting from 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i;

	if (*head == NULL) /* Empty list */
		return (-1);

	/* If the node to be deleted is the first node */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse to the node at the specified index */
	for (i = 0; i < index; i++)
	{
		if (current == NULL)
			return (-1); /* Index out of bounds */
		current = current->next;
	}

	/* Update pointers to skip the node to be deleted */
	if (current->prev != NULL)
		current->prev->next = current->next;

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
