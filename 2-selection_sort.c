#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                   using the Selection sort algorithm.
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t c, j, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (c = 0; c < size - 1; c++)
	{
		min_index = c;
		for (j = c + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != c)
		{
			temp = array[c];
			array[c] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
