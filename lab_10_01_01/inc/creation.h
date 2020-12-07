#ifndef CREATION_H
#define CREATION_H

#include "errors.h"

song_t *song_create(char *group, char *title);

node_t *node_create(void *value);

node_t *list_add_end(node_t *head, node_t *node);

#endif // CREATION_H
