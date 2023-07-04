#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: Double pointer to a char that we want to update.
 * @to: Pointer to a char whose value will be set.
 */
void set_string(char **s, char *to)
{
*s = to;
}
