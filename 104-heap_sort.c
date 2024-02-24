#include "sort.h"

void swap_elements(int *a, int *b);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_elements - Swap two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */

void swap_elements(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - Rearranges the elements in the array to make it a max heap.
 * @array: Array to heapify.
 * @size: Size of the array.
 * @base: Base index.
 * @root: Root index.
 */

void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, largest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	if (left < base && array[left] > array[largest])
		largest = left;
	if (right < base && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap_elements(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, size, base, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: Array of integers.
 * @size: Size of the array.
 */

void heap_sort(int *array, size_t size)
{
	int c;

	if (array == NULL || size < 2)
		return;

	for (c = (size / 2) - 1; c >= 0; c--)
		heapify(array, size, size, c);

	for (c = size - 1; c > 0; c--)
	{
		swap_elements(&array[0], &array[c]);
		print_array(array, size);
		heapify(array, size, c, 0);
	}
}
