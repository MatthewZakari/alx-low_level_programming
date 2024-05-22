#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 *		or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *prev;

	if (!list)
		return (NULL);

	node = list;
	while (node->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->express->index,
				node->express->n);
		if (node->express->n >= value)
			break;
		node = node->express;
	}

	if (!node->express)
	{
		prev = node;
		while (node->next)
			node = node->next;
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
				node->index);
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n", node->index,
				node->express->index);
	}

	prev = node;
	while (prev && prev->index <= node->express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
