#ifndef LIST_TOOLS_H
#define LIST_TOOLS_H

#include "errors.h"

node_t *node_create(char *value);

node_t *list_add_end(node_t *head, node_t *node);

void list_free(node_t *head);

#endif // LIST_TOOLS_H
