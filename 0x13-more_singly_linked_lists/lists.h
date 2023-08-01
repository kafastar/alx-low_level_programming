#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
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

/* Function prototypes */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

/* Function prototypes */
int sum_listint(listint_t *head);

/* Function prototypes */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

/* Function prototypes */
int delete_nodeint_at_index(listint_t **head, unsigned int index);

/* Function prototypes */
listint_t *reverse_listint(listint_t **head);

/* Function prototypes */
size_t print_listint_safe(const listint_t *head);

/* Function prototypes */
size_t free_listint_safe(listint_t **h);

/* Function prototypes */
listint_t *find_listint_loop(listint_t *head);

#endif /* LISTS_H */

