#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 *
 * @array: The array to be partitioned
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot after partitioning
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	size_t pivot = array[high];
	int c = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < (int)pivot)
		{
			c++;
			temp = array[c];
			array[c] = array[j];
			array[j] = temp;
			if (c != j)
				print_array(array, size);
		}
	}
	temp = array[c + 1];
	array[c + 1] = array[high];
	array[high] = temp;
	if (c + 1 != high)
		print_array(array, size);
	return (c + 1);
}

/**
 * quicksort - Recursive function to sort an array using quicksort
 *
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm.
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

