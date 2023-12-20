#include "sort.h"

void swap_node_ahead_PEC(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind_PEC(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead_PEC - Swap a node in at.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker_PEC: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker_PEC)
{
	listint_t *tmp = (*shaker_PEC)->next;

	if ((*shaker_PEC)->prev != NULL)
		(*shaker_PEC)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker_PEC)->prev;
	(*shaker_PEC)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker_PEC;
	else
		*tail = *shaker_PEC;
	(*shaker_PEC)->prev = tmp;
	tmp->next = *shaker_PEC;
	*shaker_PEC = tmp;
}

/**
 * swap_node_behind_PEC - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker_PEC: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind_PEC(listint_t **list, listint_t **tail, listint_t **shaker_PEC)
{
	listint_t *tmp = (*shaker_PEC)->prev;

	if ((*shaker_PEC)->next != NULL)
		(*shaker_PEC)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker_PEC)->next;
	(*shaker_PEC)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker_PEC;
	else
		*list = *shaker_PEC;
	(*shaker_PEC)->next = tmp;
	tmp->prev = *shaker_PEC;
	*shaker_PEC = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker_PEC;
	bool shaken_not_stirred_PEC = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred_PEC == false)
	{
		shaken_not_stirred_PEC = true;
		for (shaker_PEC = *list; shaker_PEC != tail; shaker_PEC = shaker_PEC->next)
		{
			if (shaker_PEC->n > shaker_PEC->next->n)
			{
				swap_node_ahead_PEC(list, &tail, &shaker_PEC);
				print_list((const listint_t *)*list);
				shaken_not_stirred_PEC = false;
			}
		}
		for (shaker_PEC = shaker_PEC->prev; shaker_PEC != *list;
				shaker_PEC = shaker_PEC->prev)
		{
			if (shaker_PEC->n < shaker_PEC->prev->n)
			{
				swap_node_behind_PEC(list, &tail, &shaker_PEC);
				print_list((const listint_t *)*list);
				shaken_not_stirred_PEC = false;
			}
		}
	}
}
