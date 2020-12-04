#ifndef TASK_H
#define TASK_H

#include "errors.h"

node_t *concatenation(node_t *head_a, node_t **head_b);

void remove_duplicates(node_t *head);

int search(node_t *head_1, node_t *head_2, int *pos);

#endif // TASK_H
