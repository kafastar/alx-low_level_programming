#include <stdlib.h>

/**
 * _strdup - Creates a duplicate of a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL if insufficient memory
 *         was available or if str is NULL
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length = 0;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	duplicate = malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}
