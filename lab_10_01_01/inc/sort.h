#ifndef SORT_H
#define SORT_H

#include "errors.h"

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

void front_back_split(node_t *head, node_t **back);

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));

#endif // SORT_H
