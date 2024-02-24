#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int max, c;

	for (max = array[0], c = 1; c < size; c++)
	{
		if (array[c] > max)
			max = array[c];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t c;

	for (c = 0; c < size; c++)
		count[(array[c] / sig) % 10] += 1;

	for (c = 1; c < 10; c++)
		count[c] += count[c - 1];

	for (c = size; c > 0; c--)
	{
		buff[count[(array[c - 1] / sig) % 10] - 1] = array[c - 1];
		count[(array[c - 1] / sig) % 10] -= 1;
	}

	for (c = 0; c < size; c++)
		array[c] = buff[c];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
