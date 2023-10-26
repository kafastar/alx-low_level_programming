#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number to change.
 * @index: The index, starting from 0, of the bit to set.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)  /* unsigned long int is usually 8 bytes = 64 bits */
		return (-1);

	/* Shift 1 to the left 'index' times and OR with *n */
	*n |= (1UL << index);
	return (1);
}
