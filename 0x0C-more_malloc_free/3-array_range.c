#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the minimum value of the array
 * @max: the maximum value of the array
 * Return: a pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *array;
	int i, len;

	/* check if min > max */
	if (min > max)
		return (NULL);

	/* calculate the length of the array */
	len = max - min + 1;

	/* allocate memory for the array using malloc */
	array = malloc(sizeof(int) * len);
	if (array == NULL) /* check if malloc failed */
		return (NULL);

	/* fill the array with values from min to max */
	for (i = 0; i < len; i++)
		array[i] = min + i;

	/* return the pointer to the newly created array */
	return (array);
}
