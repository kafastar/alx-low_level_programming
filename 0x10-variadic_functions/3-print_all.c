#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_char - Print a char argument.
 * @valist: The argument list.
 */
void print_char(va_list valist)
{
	printf("%c", va_arg(valist, int));
}

/**
 * print_int - Print an integer argument.
 * @valist: The argument list.
 */
void print_int(va_list valist)
{
	printf("%d", va_arg(valist, int));
}

/**
 * print_float - Print a float argument.
 * @valist: The argument list.
 */
void print_float(va_list valist)
{
	printf("%f", va_arg(valist, double));
}

/**
 * print_string - Print a string argument.
 * @valist: The argument list.
 */
void print_string(va_list valist)
{
	char *str = va_arg(valist, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - Prints anything.
 * @format: The format string representing the types of arguments.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s", separator);
				print_char(args);
				break;
			case 'i':
				printf("%s", separator);
				print_int(args);
				break;
			case 'f':
				printf("%s", separator);
				print_float(args);
				break;
			case 's':
				printf("%s", separator);
				print_string(args);
				break;
			default:
				break;
		}
		separator = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}
