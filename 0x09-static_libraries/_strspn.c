#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    while (*s != '\0')
    {
        int found = 0;
        char *a = accept;
        while (*a != '\0')
        {
            if (*s == *a)
            {
                found = 1;
                break;
            }
            a++;
        }
        if (found)
            count++;
        else
            break;
        s++;
    }
    return count;
}
