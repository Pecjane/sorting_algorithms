#include "sort.h"

void swap_ints_PEC(int *a_PEC, int *b_PEC);
int lomuto_partition_PEC(int *array, size_t size, int left, int right);
void lomuto_sort_PEC(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints_PEC - Swap two integers in an array.
 * @a_PEC: first integer
 * @b_PEC:  sec integer
 */
void swap_ints_PEC(int *a_PEC, int *b_PEC)
{
	int tmp;

	tmp = *a_PEC;
	*a_PEC = *b_PEC;
	*b_PEC = tmp;
}

/**
 * lomuto_partition_PEC - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: final partition index.
 */
int lomuto_partition_PEC(int *array, size_t size, int left, int right)
{
	int *pivot_PEC, above, below;

	pivot_PEC = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot_PEC)
		{
			if (above < below)
			{
				swap_ints_PEC(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot_PEC)
	{
		swap_ints_PEC(array + above, pivot_PEC);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort_PEC - Implement the quicksort
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: it is using partition scheme.
 */
void lomuto_sort_PEC(int *array, size_t size, int left, int right)
{
	int part_PEC;

	if (right - left > 0)
	{
		part_PEC = lomuto_partition(array, size, left, right);
		lomuto_sort_PEC(array, size, left, part - 1);
		lomuto_sort_PEC(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts  arrays of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort_PEC(array, size, 0, size - 1);
}
