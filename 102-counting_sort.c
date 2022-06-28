#include "sort.h"
/**
 * catch_max - catch maximum value in an array.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
 */
int catch_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sorts an array in ascending order using the Counting sort
 * @array: array to ordering
 * @size: size of array.
 */
void counting_sort(int *array, size_t size)
{
	int *sort, *coun, max, i;

	if (array == NULL || size < 2)
		return;
	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = catch_max(array, size);
	coun = malloc(sizeof(int) * (max + 1));
	if (coun == NULL)
		return;
	for (i = 0; i < (max + 1); i++)
		coun[i] = 0;
	for (i = 0; i < (int)size; i++)
		coun[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		coun[i] += coun[i - 1];
	print_array(coun, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		sort[coun[array[i]] - 1] = array[i];
		coun[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];
	free(sort);
	free(coun);
}
