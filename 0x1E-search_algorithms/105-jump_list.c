#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly
 *		linked list using the Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 *		or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, i;
	listint_t *node, *prev_node;

	if (!list || size == 0)
		return (NULL);

	step = sqrt(size);
	node = list;

	while (node && node->index < size && node->n < value)
	{
		prev_node = node;
		for (i = 0; node->next && i < step; i++)
			node = node->next;
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);

		if (node->n >= value)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev_node->index, node->index);

	for (node = prev_node; node && node->index < size && node->n <= value;
			node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
	}

	return (NULL);
}

