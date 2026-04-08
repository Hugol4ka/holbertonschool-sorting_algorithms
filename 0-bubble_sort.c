#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
size_t i = 0;
/* On l'initialise à 1 pour l'entrée dans la boucle la première fois */
int swapped = 1;
int temp;

	if (array == NULL || size < 2)
		return;
	while (swapped == 1)
	{
		/* On remet à zéro au début de chaque passage */
		swapped = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/*SWAP*/
				temp = array[i];
				array[i] = array[i + 1];
				 array[i + 1] = temp;
				 /*Affichage*/
				 print_array(array, size);
				/*Flag vérif swap*/
				swapped = 1;
			}
		}
	}
}
