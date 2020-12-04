#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include "errors.h"

void print(node_t *head);

int list_create(node_t **head, FILE *f);

void compact(node_t *head);

#endif // TOOLS_H
