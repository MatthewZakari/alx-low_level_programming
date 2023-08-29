#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: Pointer to a pointer to the head node.
 *
 * Return: The data (n) of the deleted head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (*head == NULL)
	{
		return (0);
	}

	temp = *head;       /* Save a reference to the current head */
	data = temp->n;     /* Get the data of the current head node */
	*head = temp->next; /* Update the head to the next node */

	free(temp);         /* Free the memory of the old head node */
	return (data);
}

