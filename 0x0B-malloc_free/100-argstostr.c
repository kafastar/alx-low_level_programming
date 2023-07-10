#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of a program
 * @ac: The argument count
 * @av: The argument vector
 *
 * Return: Pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, len = 0, total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		total_len += len;
		len = 0;
	}

	str = malloc((total_len + ac + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			str[k++] = av[i][j];
		str[k++] = '\n';
	}

	str[k] = '\0';

	return (str);
}
