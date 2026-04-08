#include "sort.h"

/**
 * swap_nodes - Swaps a node with its previous one in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node: Pointer to the node to swap backwards
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev_node;

	prev_node = node->prev;

	prev_node->next = node->next;
	if (node->next != NULL)
		node->next->prev = prev_node;

	node->prev = prev_node->prev;
	if (prev_node->prev != NULL)
		prev_node->prev->next = node;
	else
		*list = node;

	node->next = prev_node;
	prev_node->prev = node;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	iter = (*list)->next;

	while (iter != NULL)
	{
		insert_node = iter;
		iter = iter->next;

		while (insert_node->prev != NULL && insert_node->prev->n > insert_node->n)
		{
			swap_nodes(list, insert_node);
			print_list((const listint_t *)*list);
		}
	}
}
