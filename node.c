#include <stdlib.h>

#include "node.h"

static struct node *create_node(void *data, size_t data_size)
{
    struct node *new = calloc(1, sizeof(struct node));

    if (!new)
        return (NULL);
    new->data = calloc(1, data_size);
    if (!new->data)
        return (NULL);
    for (size_t i = 0; i < data_size; i++)
        *(char *)(new->data + i) = *(char *)(data + i); 
    return (new);  
}

void push_node(struct node **head, void *data, size_t data_size)
{
    struct node *it = *head;

    if (!(*head)) {
        *head = create_node(data, data_size);
        return;
    }
    while (it->next)
        it = it->next;
    it->next = create_node(data, data_size);
    it->next->prev = it;
}

void pop_node(struct node **head, void (*fct)(void *data))
{
    struct node *n = *head;

    *head = (*head)->next;
    if (*head)
        (*head)->prev = NULL;
    if (fct)
        fct(n->data);
    else
        free(n->data);
    free(n);
}

void destroy_list(struct node *head, void (*fct)(void *data))
{
    while (head)
        pop_node(&head, fct);
}

void dump_list(struct node *head, void (*fct)(void *data))
{
    struct node *it = head;

    for (; it; it = it->next)
        fct(it->data);
}