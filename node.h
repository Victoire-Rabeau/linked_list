#ifndef NODE_H_
#define NODE_H_

#include <unistd.h>

struct node
{
    void *data;
    struct node *prev;
    struct node *next;  
};

void push_node(struct node **head, void *data, size_t data_size);

void pop_node(struct node **head, void (*fct)(void *data));

void destroy_list(struct node *head, void (*fct)(void *data));

void dump_list(struct node *head, void (*fct)(void *data));

#endif /* !NODE_H_ */