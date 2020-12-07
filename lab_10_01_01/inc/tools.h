#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include "errors.h"

void print(node_t *head, FILE *f);

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

int comparator(const void *ptr1, const void *ptr2);

#endif // TOOLS_H
