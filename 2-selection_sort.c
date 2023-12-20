#include "sort.h"

/**
 * swap_ints_PEC - Swap integers in  arrays.
 * @a_PEC: The first integer to swap.
 * @b_PEC: The second integer to swap.
 */
void swap_ints_PEC(int *a_PEC, int *b_PEC)
{
	int tmp;

	tmp = *a_PEC;
	*a_PEC = *b_PEC;
	*b_PEC = tmp;
}

/**
 * selection_sort_PEC - Sorting an array of integers
 * @array: list array of integers.
 * @size:  size of the array.
 *
 * Description: Prints all the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j_PEC;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j_PEC = i + 1; j_PEC < size; j_PEC++)
			min = (array[j_PEC] < *min) ? (array + j_PEC) : min;

		if ((array + i) != min)
		{
			swap_ints_PEC(array + i, min);
			print_array(array, size);
		}
	}
}
