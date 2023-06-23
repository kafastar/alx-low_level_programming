#include <stdio.h>

/**
 * fizzBuzz - prints numbers from 1 to 100
 *            For multiples of three, prints "Fizz" instead of the number
 *            For multiples of five, prints "Buzz" instead of the number
 *            For numbers which are multiples of both three and five, prints "FizzBuzz"
 */
void fizzBuzz(void)
{
    int i;

    for (i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            printf("FizzBuzz");
        else if (i % 3 == 0)
            printf("Fizz");
        else if (i % 5 == 0)
            printf("Buzz");
        else
            printf("%d", i);

        if (i != 100)
            printf(" ");
    }

    printf("\n");
}

/**
 * main - entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    fizzBuzz();
    return 0;
}
