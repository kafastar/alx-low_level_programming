#include "main.h"
#include <unistd.h>

/**
 * puts2 - Prints every other character of a string.
 * @str: The input string.
 */
void puts2(char *str)
{
	int i;
	int len = 0;

	/* Calculate the length of the string */
	while (str[len] != '\0')
		len++;

	/* Print every other character */
	for (i = 0; i < len; i += 2)
		write(1, &str[i], 1);

	write(1, "\n", 1);
}
