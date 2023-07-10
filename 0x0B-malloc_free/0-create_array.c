#include <stdlib.h>

/**
 * create_array - Create an array and initialize it with a specific character
 * @size: The size of the array
 * @c: The character to initialize the array with
 *
 * Return: Pointer to the created array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(size * sizeof(*array));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
