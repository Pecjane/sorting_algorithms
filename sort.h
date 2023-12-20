#ifndef JANE_H
#define JANE_H

#include <stdlib.h>
#include <stdio.h>

/*(difference between macros */
#define BY 0
#define BYE 1

/**
 * enum  bool - Enumarate
 * @false_pj: Same as 0
 * @true_pj: Same as 1
 */

typedef enum bool
{
	false_pj = 0;
	true_pj
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/*prints helper funt*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*sorting algoritms */
void bubble_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* JANE_H */
