#include "sort.h"

/**
* swap_ints - Swaps two integers in an array.
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*/
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* lomuto_partition - Orders a subset of an array of integers according to
* the Lomuto partition scheme (last element as pivot).
* @array: The array of integers.
* @size: The total size of the array (used for printing).
* @left: The starting index of the subset to order.
* @right: The ending index of the subset to order.
*
* Return: The final index of the pivot.
*/
static int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot;
	int above, below;

	pivot = array + right;
	above = left;

	for (below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + above, array + below);
				print_array(array, size);
			}
			above++;
		}
	}

    /* Échange final du pivot */
	if (array[above] > *pivot)
	{
	swap_ints(array + above, pivot);
	print_array(array, size);
	}

	return (above);
}

/**
* lomuto_sort - Implements the quicksort algorithm through recursion.
* @array: An array of integers to sort.
* @size: The total size of the array.
* @left: The starting index of the array partition to order.
* @right: The ending index of the array partition to order.
*/
static void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	/* Base case: if the partition has 1 or fewer elements, it is sorted */
	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);

		/* Recursively sort the left and right halves */
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using
* the Quick sort algorithm (Lomuto partition scheme).
* @array: An array of integers.
* @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	/* Security check */
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
