#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp;
	int first = 1; /* Flag to check if it's the first pair to print */

       if (!ht)
	       return;

       printf("{");
       for (i = 0; i < ht->size; i++)
       {
	       temp = ht->array[i];
	       while (temp)
	       {
		       if (!first)
			       printf(", ");
		       printf("'%s': '%s'", temp->key, temp->value);
		       first = 0;
		       temp = temp->next;
	       }
       }
       printf("}\n");
}
