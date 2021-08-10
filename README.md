# Linked list

This is a generic C linked lists implementation.

## Synopsis

```c
void push_node(struct node **head, void *data, size_t data_size);

void pop_node(struct node **head, void (*fct)(void *data));

void destroy_list(struct node *head, void (*fct)(void *data));

void dump_list(struct node *head, void (*fct)(void *data));
```

## Description

The **push_node()** function adds a new node at the end of the list, filled with the *data* parameter;

The **pop_node()** function removes and frees the first node of the list by calling the function passed as parameter if it is not NULL.

The **destroy_node()** function removes and frees all the nodes of the list by calling the function passed as parameter if it is not NULL.

The **dump_list()** functions enables to dump all the nodes by calling the function passed as parameter.