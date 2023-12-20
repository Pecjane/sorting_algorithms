#include "sort.h"

/**
 * swap_ints_PEC - Swaps two integers in an array.
 * @a_PEC: The first integer
 * @b_PEC: The sec integer
 */
void swap_ints_PEC(int *a_PEC, int *b_PEC)
{
	int tmp;

	tmp = *a_PEC;
	*a_PEC = *b_PEC;
	*b_PEC = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t gap_PEC, i, j_PEC;

	if (array == NULL || size < 2)
		return;

	for (gap_PEC = 1; gap_PEC < (size / 3);)
		gap_PEC = gap_PEC * 3 + 1;

	for (; gap_PEC >= 1; gap_PEC /= 3)
	{
		for (i = gap_PEC; i < size; i++)
		{
			j_PEC = i;
			while (j_PEC >= gap_PEC && array[j - gap_PEC] > array[j])
			{
				swap_ints_PEC(array + j_PEC, array + (j_PEC - gap_PEC));
				j_PEC -= gap;
			}
		}
		print_array(array, size);
	}
}
