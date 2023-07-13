#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: the number of bytes to allocate
 * Return: a pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b); /* allocate memory using malloc */
	if (p == NULL) /* check if malloc failed */
	{
		exit(98); /* terminate the process with status 98 */
	}
	return (p); /* return the pointer to the allocated memory */
}
