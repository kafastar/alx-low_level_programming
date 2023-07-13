#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: the number of elements of the array
 * @size: the size of each element in bytes
 * Return: a pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *array;
	char *filler;
	unsigned int i;

	/* check if nmemb or size is 0 */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* allocate memory for the array using malloc */
	array = malloc(nmemb * size);
	if (array == NULL) /* check if malloc failed */
		return (NULL);

	/* cast the pointer to char type for easy filling */
	filler = (char *)array;

	/* fill the memory with zeros */
	for (i = 0; i < (nmemb * size); i++)
		filler[i] = 0;

	/* return the pointer to the allocated memory */
	return (array);
}
