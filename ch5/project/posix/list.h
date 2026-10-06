#ifndef LIST_H
#define LIST_H

/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

typedef void (*actor)(Task*);

struct node {
    Task *task;
    struct node *next;
};

// insert and delete operations.
void insert(struct node **head, Task *task);
void delete(struct node **head, Task *task);
void traverse_cb(struct node *head, actor cb);
void traverse(struct node *head);

#endif
