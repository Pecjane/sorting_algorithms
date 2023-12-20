#include "sort.h"

/**
 * swap_ints_PEC - integers in an array.
 * @a_PEC: The first integer to swap.
 * @b_PEC: The second integer to swap.
 */
void swap_ints(int *a_PEC, int *b_PEC)
{
	int tmp_PEC;

	tmp_PEC = *a_PEC;
	*a_PEC = *b_PEC;
	*b_PEC = tmp_PEC;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len_PEC = size;
	bool bubbly_PEC = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly_PEC == false)
	{
		bubbly_PEC = true;
		for (i = 0; i < len_PEC - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints_PEC(array + i, array + i + 1);
				print_array(array, size);
				bubbly_PEC = false;
			}
		}
		len_PEC--;
	}
}
