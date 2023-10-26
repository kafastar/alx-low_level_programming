#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to get the bit from.
 * @index: The index, starting from 0, of the bit to get.
 *
 * Return: The value of the bit at index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63) /* unsigned long int is usually 8 bytes = 64 bits */
		return (-1);

	/* Shift 'n' right by 'index' bits and & with 1 */
	return ((n >> index) & 1);
}
