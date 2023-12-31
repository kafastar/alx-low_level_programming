#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int flag;

	mask = 1UL << ((sizeof(unsigned long int) * 8) - 1);
	flag = 0;

	while (mask)
	{
		if ((n & mask) == mask)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
		{
			_putchar('0');
		}
		mask >>= 1;
	}

	if (!flag)
		_putchar('0');
}
