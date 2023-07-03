#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix
 * @a: Pointer to the first element of the matrix
 * @size: Size of the matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += *(a + (size * i) + i);               /* Sum of elements from top-left to bottom-right diagonal */
		sum2 += *(a + (size * (i + 1)) - (i + 1));   /* Sum of elements from top-right to bottom-left diagonal */
	}

	printf("%d, %d\n", sum1, sum2);
}
