#include "sort.h"

/**
 * swap_nodes_PEC - Swaps nodes in doubly-linked list.
 * @h_PEC: A head of the doubly-linked list.
 * @n1_PEC: A pointer to the first node to swap.
 * @n2_PEC: The second node to swap.
 */
void swap_nodes_PEC(listint_t **h_PEC, listint_t **n1_PEC, listint_t *n2_PEC)
{
	(*n1_PEC)->next = n2_PEC->next;
	if (n2_PEC->next != NULL)
		n2_PEC->next->prev = *n1_PEC;
	n2_PEC->prev = (*n1_PEC)->prev;
	n2_PEC->next = *n1_PEC;
	if ((*n1_PEC)->prev != NULL)
		(*n1_PEC)->prev->next = n2_PEC;
	else
		*h_PEC = n2_PEC;
	(*n1_PEC)->prev = n2_PEC;
	*n1_PEC = n2_PEC->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Printing the list after all swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter_PEC, *insert_PEC, *tmp

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter_PEC = (*list)->next; iter_PEC != NULL; iter_PEC = tmp)
	{
		tmp = iter->next;
		insert_PEC = iter_PEC->prev;
		while (insert_PEC != NULL && iter_PEC->n < insert_PEC->n)
		{
			swap_nodes_PEC(list, &insert_PEC, iter_PEC);
			print_list((const listint_t *)*list);
		}
	}
}
