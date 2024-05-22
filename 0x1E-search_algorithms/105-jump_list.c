#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly
 * 		linked list using the Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, prev;
	listint_t *node, *prev_node;

	if (!list || size == 0)
		return (NULL);

	step = sqrt(size);
	prev = 0;
	node = list;

	while (node && node->index < size && node->n < value)
	{
		prev_node = node;
		for (prev = node->index; node->next && node->index < prev + step;
				node = node->next)
			;
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, node->index);

	for (node = prev_node; node && node->index <= prev + step && node->n <= value;
			node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
	}

	return (NULL);
}

