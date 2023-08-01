#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Structure for a singly linked list node */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
size_t print_listint(const listint_t *h);

/* Function prototypes */
size_t listint_len(const listint_t *h);

/* Function prototypes */
listint_t *add_nodeint(listint_t **head, const int n);

/* Function prototypes */
listint_t *add_nodeint_end(listint_t **head, const int n);

/* Function prototypes */
void free_listint(listint_t *head);

/* Function prototypes */
void free_listint2(listint_t **head);

/* Function prototypes */
int pop_listint(listint_t **head);

#endif /* LISTS_H */

